/*
232. Implement Queue using Stacks

https://leetcode.com/problems/implement-queue-using-stacks/

- 225. Implement Stack using Queues
*/
class MyQueue {
  in: number[] = [];
  out: number[] = [];

  constructor() {}

  push(x: number): void {
    this.in.push(x);
  }

  pop(): number {
    if (this.empty()) return -1;
    if (this.out.length == 0) {
      // out is empty
      while (this.in.length > 0) {
        this.out.push(this.in.pop()!);
      }
    }
    return this.out.pop()!;
  }

  peek(): number {
    if (this.empty()) return -1;
    if (this.out.length == 0) {
      // out is empty
      while (this.in.length > 0) {
        this.out.push(this.in.pop()!);
      }
    }
    return this.out[this.out.length - 1];
  }

  empty(): boolean {
    return this.in.length == 0 && this.out.length == 0;
  }
}

export {};
