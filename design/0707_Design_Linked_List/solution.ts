/*
707. Design Linked List

https://leetcode.com/problems/design-linked-list/
*/

/*
HuaHua
https://www.youtube.com/watch?v=dmezFFv522I

Keep tracking head and tail of the list.

*/
class Node {
  val: number;
  next: Node | null;

  constructor(val: number, next: Node | null = null) {
    this.val = val;
    this.next = next;
  }
}

class MyLinkedList {
  private head: Node | null;
  private tail: Node | null;
  private size: number;

  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  get(index: number): number {
    if (index < 0 || index >= this.size) return -1;
    const node = this.getNode(index);
    return node ? node.val : -1;
  }

  addAtHead(val: number): void {
    const newNode = new Node(val, this.head);
    this.head = newNode;
    if (this.size++ === 0) {
      this.tail = newNode;
    }
  }

  addAtTail(val: number): void {
    const newNode = new Node(val);
    if (this.size++ === 0) {
      this.head = this.tail = newNode;
    } else if (this.tail) {
      this.tail.next = newNode;
      this.tail = newNode;
    }
  }

  addAtIndex(index: number, val: number): void {
    if (index < 0 || index > this.size) return;
    if (index === 0) {
      this.addAtHead(val);
    } else if (index === this.size) {
      this.addAtTail(val);
    } else {
      const prev = this.getNode(index - 1);
      if (prev) {
        const newNode = new Node(val, prev.next);
        prev.next = newNode;
        this.size++;
      }
    }
  }

  deleteAtIndex(index: number): void {
    if (index < 0 || index >= this.size) return;
    if (index === 0) {
      if (this.head) {
        this.head = this.head.next;
        if (this.size-- === 1) this.tail = null;
      }
    } else {
      const prev = this.getNode(index - 1);
      if (prev && prev.next) {
        if (prev.next === this.tail) this.tail = prev;
        prev.next = prev.next.next;
        this.size--;
      }
    }
  }

  private getNode(index: number): Node | null {
    let current = this.head;
    for (let i = 0; i < index && current !== null; i++) {
      current = current.next;
    }
    return current;
  }
}

export {};
