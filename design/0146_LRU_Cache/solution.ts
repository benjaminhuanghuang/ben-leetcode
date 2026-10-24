/*
146. LRU Cache

Least recently used (LRU)

The functions get and put must each run in O(1) average time complexity.
*/

/*
https://algo.monster/liteproblems/146

*/

/*
  Use a double linked list and a Key-Node map
*/
class CacheNode {
  value: number;
  key: number;
  next: CacheNode | null;
  prev: CacheNode | null;

  constructor(key: number, value: number) {
    this.key = key;
    this.value = value;
    this.prev = null;
    this.next = null;
  }
}

// maintain the order of usage and rearrange nodes in O(1) time
class DLinkedList {
  head: CacheNode | null;
  tail: CacheNode | null;

  constructor() {
    this.head = null;
    this.tail = null;
  }

  addToHead(node: CacheNode): void {
    if (!this.head) {
      this.head = node;
      this.tail = node;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
  }

  removeNode(node: CacheNode): void {
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
  }

  moveToHead(node: CacheNode): void {
    this.removeNode(node);
    this.addToHead(node);
  }

  removeTail(): CacheNode | null {
    if (!this.tail) return null;
    const tail = this.tail;
    this.removeNode(tail);
    return tail;
  }
}

class LRUCache {
  private capacity: number;
  private map: Map<number, CacheNode>;
  private list: DLinkedList;

  constructor(capacity: number) {
    this.capacity = capacity;
    this.map = new Map<number, CacheNode>();
    this.list = new DLinkedList();
  }

  get(key: number): number {
    const node = this.map.get(key);
    if (!node) return -1;

    this.list.moveToHead(node); // Head is the recent used node
    return node.value;
  }

  put(key: number, value: number): void {
    const node = this.map.get(key);

    if (node) {
      node.value = value;
      this.list.moveToHead(node); // Head is the recent used node
    } else {
      const newNode = new CacheNode(key, value);
      if (this.map.size >= this.capacity) {
        const tail = this.list.removeTail();
        if (tail) {
          this.map.delete(tail.key);
        }
      }

      this.list.addToHead(newNode);
      this.map.set(key, newNode);
    }
  }
}
