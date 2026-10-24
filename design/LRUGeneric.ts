/*

Node Class: Represents each node in the doubly linked list.
Doubly Linked List Class: Handles the operations of the linked list.
LRU Cache Class: Manages the cache using the linked list and a map.
*/

class LRUNode<K, V> {
  key: K;
  value: V;
  prev: LRUNode<K, V> | null;
  next: LRUNode<K, V> | null;

  constructor(key: K, value: V) {
    this.key = key;
    this.value = value;
    this.prev = null;
    this.next = null;
  }
}
class DoublyLinkedList<K, V> {
  head: LRUNode<K, V> | null;
  tail: LRUNode<K, V> | null;

  constructor() {
    this.head = null;
    this.tail = null;
  }

  addToHead(node: LRUNode<K, V>): void {
    if (!this.head) {
      this.head = node;
      this.tail = node;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
  }

  removeNode(node: LRUNode<K, V>): void {
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

  moveToHead(node: LRUNode<K, V>): void {
    this.removeNode(node);
    this.addToHead(node);
  }

  removeTail(): LRUNode<K, V> | null {
    if (!this.tail) return null;
    const tail = this.tail;
    this.removeNode(tail);
    return tail;
  }
}

class LRUCacheGeneric<K, V> {
  private capacity: number;
  private map: Map<K, LRUNode<K, V>>;
  private list: DoublyLinkedList<K, V>;

  constructor(capacity: number) {
    this.capacity = capacity;
    this.map = new Map<K, LRUNode<K, V>>();
    this.list = new DoublyLinkedList<K, V>();
  }

  get(key: K): V | null {
    const node = this.map.get(key);
    if (!node) return null;

    this.list.moveToHead(node); // Head is the recent used node
    return node.value;
  }

  put(key: K, value: V): void {
    const node = this.map.get(key);

    if (node) {
      node.value = value;
      this.list.moveToHead(node); // Head is the recent used node
    } else {
      const newNode = new LRUNode(key, value);
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
