/*
703. Kth Largest Element in a Stream

https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

import { PriorityQueue } from "./PriorityQueue";

class KthLargest {
  // min heap, the smallest element will pop out first
  pq: PriorityQueue<number>;

  constructor(k: number, nums: number[]) {
    this.pq = new PriorityQueue<number>((a, b) => a < b, k);
    for (const num of nums) {
      this.pq.add(num);
    }
  }

  add(val: number): number {
    this.pq.add(val);
    return this.pq.peek()!;
  }
}
