/*
225. Implement Stack using Queues

https://leetcode.com/problems/implement-stack-using-queues/

- 232. Implement Queue using Stacks
*/

class MyStack {
  outQueue: number[] = [];
  inQueue: number[] = [];
  constructor() {}

  push(x: number): void {
    // Push the element into the secondary queue
    this.inQueue.push(x);

    // Move all elements from the primary queue to the secondary queue
    while (this.outQueue.length) {
      this.inQueue.push(this.outQueue.shift()!);
    }

    // Swap the names of the queues, making the secondary queue the new primary queue
    [this.outQueue, this.inQueue] = [this.inQueue, this.outQueue];
  }

  pop(): number {
    return this.outQueue.shift()!;
  }

  top(): number {
    return this.outQueue[0];
  }

  empty(): boolean {
    return this.outQueue.length === 0;
  }
}
