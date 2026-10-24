/*
622. Design Circular Queue
https://leetcode.com/problems/design-circular-queue
*/

class MyCircularQueue_Error {
  private queue: number[];
  private front: number;
  private rear: number;
  private capacity: number;

  constructor(k: number) {
    this.queue = new Array(k);
    this.capacity = k;
    this.front = 0;
    this.rear = 0;
  }

  // store the value at the rear of the queue and update the rear pointer
  enQueue(value: number): boolean {
    if (this.isFull()) {
      return false;
    }
    this.queue[this.rear] = value;
    this.rear = (this.rear + 1) % this.capacity;
    return true;
  }

  // remove the value at the front of the queue and update the front pointer
  deQueue(): boolean {
    if (this.isEmpty()) {
      return false;
    }
    this.front = (this.front + 1) % this.capacity;
    return true;
  }

  Front(): number {
    if (this.isEmpty()) {
      return -1;
    }
    return this.queue[this.front];
  }

  Rear(): number {
    if (this.isEmpty()) {
      return -1;
    }
    return this.queue[(this.rear - 1 + this.capacity) % this.capacity];
  }

  isEmpty(): boolean {
    return this.front === this.rear;
  }

  // check if the next index of the rear pointer is the front pointer
  // Bug: when capacity is 3, queue is [1, 2, -], front is 0, rear is 2, the next index of rear is 0
  isFull(): boolean {
    return (this.rear + 1) % this.capacity === this.front;
  }
}

class MyCircularQueue {
  private queue: number[];
  private front: number;
  private rear: number;
  private capacity: number;
  private count: number;

  constructor(k: number) {
    this.queue = new Array(k);
    this.capacity = k;
    this.front = 0;
    this.rear = 0;
    this.count = 0;
  }

  // store the value at the rear of the queue and update the rear pointer
  enQueue(value: number): boolean {
    if (this.isFull()) {
      return false;
    }
    this.queue[this.rear] = value;
    this.rear = (this.rear + 1) % this.capacity;
    this.count++;
    return true;
  }

  // remove the value at the front of the queue and update the front pointer
  deQueue(): boolean {
    if (this.isEmpty()) {
      return false;
    }
    this.front = (this.front + 1) % this.capacity;
    this.count--;
    return true;
  }

  Front(): number {
    if (this.isEmpty()) {
      return -1;
    }
    return this.queue[this.front];
  }

  Rear(): number {
    if (this.isEmpty()) {
      return -1;
    }
    return this.queue[(this.rear - 1 + this.capacity) % this.capacity];
  }

  isEmpty(): boolean {
    return this.count === 0;
  }

  // check if the queue is full
  isFull(): boolean {
    return this.count === this.capacity;
  }
}

export { MyCircularQueue_Error };
