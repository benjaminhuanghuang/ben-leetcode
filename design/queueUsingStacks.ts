class MyQueue {
  // Using two stacks
  private stackIn: number[];
  private stackOut: number[];

  constructor() {
    this.stackIn = [];
    this.stackOut = [];
  }

  push(x: number): void {
    // Push element x to the back of the queue
    this.stackIn.push(x);
  }

  pop(): number {
    // Remove and return the element from the front of the queue
    if (this.stackOut.length === 0) {
      while (this.stackIn.length > 0) {
        this.stackOut.push(this.stackIn.pop()!);
      }
    }
    return this.stackOut.pop()!;
  }

  peek(): number {
    // Return the element at the front of the queue
    if (this.stackOut.length === 0) {
      while (this.stackIn.length > 0) {
        this.stackOut.push(this.stackIn.pop()!);
      }
    }
    return this.stackOut[this.stackOut.length - 1];
  }

  empty(): boolean {
    // Return true if the queue is empty, false otherwise
    return this.stackIn.length === 0 && this.stackOut.length === 0;
  }
}
