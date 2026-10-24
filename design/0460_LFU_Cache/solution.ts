/*
460. LFU Cache

https://leetcode.com/problems/lfu-cache/

Least Frequently Used (LFU)

Items are sorted by frequency and then by the order of insertion
Remove the least frequently used item (at the tail) when the cache is full
O(1) time complexity for get and put
*/

/*
Hua Hua
https://www.youtube.com/watch?v=MCTN3MM8vHA
    Solution: Hash Map + Double Linked List
    Node {key, value, freq, pointer to frequency lists}
    Each visit, move it form freq-N list to the front of freq-N+1 list
*/
class CacheNode {
  key: number;
  value: number;
  freq: number;
  // pointer to the node in the list
  list: Set<number>;

  constructor(key: number, value: number, freq: number) {
    this.key = key;
    this.value = value;
    this.freq = freq;
    this.list = new Set([key]);
  }
}

class LFUCache {
  private capacity: number;
  private minFreq: number;
  private nodeMap: Map<number, CacheNode>; //key to node
  private freqMap: Map<number, number[]>; //freq to list of keys

  constructor(capacity: number) {
    this.capacity = capacity;
    this.minFreq = 0;
    this.nodeMap = new Map<number, CacheNode>();
    this.freqMap = new Map<number, number[]>();
  }

  get(key: number): number {
    const node = this.nodeMap.get(key);
    if (!node) return -1;
    this.touch(node); // update the freq
    return node.value;
  }

  put(key: number, value: number): void {
    if (this.capacity === 0) return;

    const node = this.nodeMap.get(key);
    if (node) {
      node.value = value;
      this.touch(node);
      return;
    }

    if (this.nodeMap.size === this.capacity) {
      this.evict();
    }

    const newNode = new CacheNode(key, value, 1);
    this.nodeMap.set(key, newNode);
    this.minFreq = 1;
    this.freqMap.set(1, [key, ...(this.freqMap.get(1) || [])]);
  }

  private touch(node: CacheNode): void {
    const prevFreq = node.freq;
    const freqList = this.freqMap.get(prevFreq) || [];
    const index = freqList.indexOf(node.key);
    if (index > -1) freqList.splice(index, 1);

    if (freqList.length === 0 && this.minFreq === prevFreq) {
      this.minFreq++;
    }

    node.freq++;
    this.freqMap.set(prevFreq, freqList);
    this.freqMap.set(node.freq, [
      node.key,
      ...(this.freqMap.get(node.freq) || []),
    ]);
  }

  private evict(): void {
    const freqList = this.freqMap.get(this.minFreq) || [];
    const keyToEvict = freqList.pop();
    if (keyToEvict !== undefined) {
      this.nodeMap.delete(keyToEvict);
    }
    if (freqList.length === 0) {
      this.freqMap.delete(this.minFreq);
    } else {
      this.freqMap.set(this.minFreq, freqList);
    }
  }
}

/*
  http://bookshadow.com/weblog/2016/11/22/leetcode-lfu-cache/


  head --- FreqNode1 ---- FreqNode2 ---- ... ---- FreqNodeN
            |               |                       |
          first           first                   first
            |               |                       |
         KeyNodeA        KeyNodeE                KeyNodeG
            |               |                       |
         KeyNodeB        KeyNodeF                KeyNodeH
            |               |                       |
         KeyNodeC         last                   KeyNodeI
            |                                       |
         KeyNodeD                                 last
            |
          last


  set(key, value)：

      如果capacity为0，忽略当前操作，结束

      如果keyDict中包含key，则替换其value，更新节点频度，结束

      否则，如果当前keyDict的长度 == capcity，移除head.last（频度最低且最老的KeyNode）

      新增KeyNode(key, value)，加入keyDict，并更新freqDict
  get(key)：

      若keyDict中包含key，则更新节点频度，返回对应的value

      否则，返回-1
      节点频度的更新：

      从keyDict中找到对应的KeyNode，然后通过KeyNode的freq值，从freqDict找到对应的FreqNode

      如果FreqNode的next节点不等于freq + 1，则在其右侧插入一个值为freq + 1的新FreqNode节点

      将KeyNode的freq值+1后，从当前KeyNode链表转移到新的FreqNode对应的KeyNode链表

      如果KeyNode移动之后，原来的FreqNode对应的KeyNode链表为空，则删除原来的FreqNode

      在操作完毕后如果涉及到head的变更，则更新head

   */
class LFUCacheNode {
  prev: LFUCacheNode | null;
  next: LFUCacheNode | null;
  count: number;
  keys: Set<number>;

  constructor(
    prev: LFUCacheNode | null,
    next: LFUCacheNode | null,
    count: number,
    key: number
  ) {
    this.prev = prev;
    this.next = next;
    this.count = count;
    this.keys = new Set([key]);
  }
}

class LFUCache2 {
  head: LFUCacheNode | null = null;
  capacity: number;
  valueMap: Map<number, number>;
  nodeMap: Map<number, LFUCacheNode>;

  constructor(capacity: number) {
    this.capacity = capacity;
    this.valueMap = new Map<number, number>();
    this.nodeMap = new Map<number, LFUCacheNode>();
  }

  get(key: number): number {
    if (this.valueMap.has(key)) {
      this.increase(key, this.valueMap.get(key)!);
    }
    return this.valueMap.get(key) ?? -1;
  }

  private increase(key: number, value: number): void {
    const node = this.nodeMap.get(key)!;
    node.keys.delete(key);

    if (!node.next) {
      node.next = new LFUCacheNode(node, null, node.count + 1, key);
    } else if (node.next.count === node.count + 1) {
      node.next.keys.add(key);
    } else {
      const newNode = new LFUCacheNode(node, node.next, node.count + 1, key);
      node.next.prev = newNode;
      node.next = newNode;
    }

    this.nodeMap.set(key, node.next);
    this.valueMap.set(key, value);

    if (node.keys.size === 0) {
      this.remove(node);
    }
  }

  private remove(node: LFUCacheNode): void {
    if (this.head === node) {
      this.head = node.next;
    } else {
      if (node.prev) node.prev.next = node.next;
      if (node.next) node.next.prev = node.prev;
    }
  }

  put(key: number, value: number): void {
    if (this.capacity === 0) return;

    if (this.valueMap.has(key)) {
      this.increase(key, value);
    } else {
      if (this.valueMap.size === this.capacity) {
        this.removeLeastFrequent();
      }
      this.valueMap.set(key, value);
      this.add(key);
    }
  }

  private add(key: number): void {
    if (!this.head) {
      this.head = new LFUCacheNode(null, null, 1, key);
    } else if (this.head.count === 1) {
      this.head.keys.add(key);
    } else {
      const newNode = new LFUCacheNode(null, this.head, 1, key);
      this.head.prev = newNode;
      this.head = newNode;
    }
    this.nodeMap.set(key, this.head);
  }

  private removeLeastFrequent(): void {
    if (!this.head) return;

    const oldestKey = this.head.keys.values().next().value;
    this.head.keys.delete(oldestKey);

    if (this.head.keys.size === 0) {
      this.remove(this.head);
    }

    this.nodeMap.delete(oldestKey);
    this.valueMap.delete(oldestKey);
  }
}

/*
Solution 3: Hash Map + Double Linked List
Need refactoring
*/

class LFUNode {
  key: number;
  value: number;
  freq: number;
  prev: LFUNode | null;
  next: LFUNode | null;

  constructor(key: number, value: number) {
    this.key = key;
    this.value = value;
    this.freq = 1;
    this.prev = null;
    this.next = null;
  }
}

class LFUDLinkedList {
  head: LFUNode | null;
  tail: LFUNode | null;
  size: number = 0;
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  addToHead(node: LFUNode): void {
    if (!this.head) {
      this.head = node;
      this.tail = node;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
    this.size++;
  }

  addToEnd(node: LFUNode): void {
    if (!this.tail) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      node.prev = this.tail;
      this.tail = node;
    }
    this.size++;
  }

  removeNode(node: LFUNode): void {
    if (node.prev) {
      node.prev.next = node.next;
    } else {
      this.head = node.next;
    }

    if (node.next) {
      node.next.prev = node.prev;
    } else {
      this.tail = node.prev;
    }

    node.prev = null;
    node.next = null;
    this.size--;
  }

  moveToHead(node: LFUNode): void {
    this.removeNode(node);
    this.addToHead(node);
  }

  removeTail(): LFUNode | null {
    if (!this.tail) return null;
    const tail = this.tail;
    this.removeNode(tail);
    return tail;
  }
}

/*
get() Time Complexity: O(1)
set() Time Complexity: O(1)
Insert / Delete / Update: Time Complexity: O(1)

Space Complexity: O(capacity)
*/
class LFUCache3 {
  capacity: number;
  keyValueMap: Map<number, LFUNode>;
  // each freq has a linked list, least recent freq is at the end
  freqMap: Map<number, LFUDLinkedList>;
  // use to track the current min frequency to remove the node when the cache is full
  minFreq: number;

  constructor(capacity: number) {
    this.capacity = capacity;
    this.keyValueMap = new Map<number, LFUNode>();
    this.freqMap = new Map<number, LFUDLinkedList>();
    this.minFreq = 0;
  }

  get(key: number): number {
    if (!this.keyValueMap.has(key)) {
      return -1;
    }
    const node = this.keyValueMap.get(key)!;
    this.freqMap.get(node.freq)!.removeNode(node);
    if (this.minFreq === node.freq && this.freqMap.get(node.freq)!.size == 0) {
      this.minFreq++;
    }
    node.freq++;
    if (!this.freqMap.has(node.freq)) {
      this.freqMap.set(node.freq, new LFUDLinkedList());
    }
    this.freqMap.get(node.freq)!.addToHead(node);
    return node.value;
  }

  put(key: number, value: number) {
    if (this.keyValueMap.has(key)) {
      const node = this.keyValueMap.get(key)!;
      this.freqMap.get(node.freq)!.removeNode(node);
      if (
        this.minFreq === node.freq &&
        this.freqMap.get(node.freq)!.size == 0
      ) {
        this.minFreq++;
      }
      node.freq++;
      node.value = value;
      if (!this.freqMap.has(node.freq)) {
        this.freqMap.set(node.freq, new LFUDLinkedList());
      }
      this.freqMap.get(node.freq)!.addToHead(node);
    } else {
      if (this.keyValueMap.size === this.capacity) {
        // remove the least frequent node from the freqMap.get(this.minFreq)
        const minFreqList = this.freqMap.get(this.minFreq)!;
        const node = minFreqList.removeTail()!;
        this.keyValueMap.delete(node.key);
      }
      const node = new LFUNode(key, value);
      this.keyValueMap.set(key, node);
      this.minFreq = 1;
      if (!this.freqMap.has(1)) {
        this.freqMap.set(1, new LFUDLinkedList());
      }
      this.freqMap.get(1)!.addToHead(node);
    }
  }
}
export {};
