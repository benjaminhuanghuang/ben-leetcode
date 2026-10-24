/*
1381. Design a Stack With Increment Operation

https://leetcode.com/problems/design-a-stack-with-increment-operation/
*/

class CustomStack {
  stack: number[];
  maxSize: number;
  constructor(maxSize: number) {
    this.stack = [];
    this.maxSize = maxSize;
  }

  push(x: number): void {
    if (this.stack.length < this.maxSize) {
      this.stack.push(x);
    }
  }

  pop(): number {
    return this.stack.length === 0 ? -1 : this.stack.pop()!;
  }

  increment(k: number, val: number): void {
    for (let i = 0; i < Math.min(k, this.stack.length); ++i) {
      this.stack[i] += val;
    }
  }
}
