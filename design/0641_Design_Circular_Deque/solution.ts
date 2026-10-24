/*
641. Design Circular Deque

https://leetcode.com/problems/design-circular-deque/
*/

class MyCircularDeque {
  private capacity: number;
  private head: number;
  private tail: number;
  private size: number;
  private data: number[];

  /** Initialize your data structure here. Set the size of the deque to be k. */
  constructor(k: number) {
    this.capacity = k;
    this.data = new Array(k);
    this.head = 1;
    this.tail = -1;
    this.size = 0;
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  insertFront(value: number): boolean {
    if (this.isFull()) return false;
    this.head = (this.head - 1 + this.capacity) % this.capacity;
    this.data[this.head] = value;
    if (this.size === 0) this.tail = this.head;
    this.size++;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  insertLast(value: number): boolean {
    if (this.isFull()) return false;
    this.tail = (this.tail + 1 + this.capacity) % this.capacity;
    this.data[this.tail] = value;
    if (this.size === 0) this.head = this.tail;
    this.size++;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  deleteFront(): boolean {
    if (this.isEmpty()) return false;
    this.head = (this.head + 1 + this.capacity) % this.capacity;
    this.size--;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  deleteLast(): boolean {
    if (this.isEmpty()) return false;
    this.tail = (this.tail - 1 + this.capacity) % this.capacity;
    this.size--;
    return true;
  }

  /** Get the front item from the deque. */
  getFront(): number {
    if (this.isEmpty()) return -1;
    return this.data[this.head];
  }

  /** Get the last item from the deque. */
  getRear(): number {
    if (this.isEmpty()) return -1;
    return this.data[this.tail];
  }

  /** Checks whether the circular deque is empty or not. */
  isEmpty(): boolean {
    return this.size === 0;
  }

  /** Checks whether the circular deque is full or not. */
  isFull(): boolean {
    return this.size === this.capacity;
  }
}
