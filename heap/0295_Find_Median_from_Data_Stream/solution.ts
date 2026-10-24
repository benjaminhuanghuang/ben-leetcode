/*
295. Find Median from Data Stream

https://leetcode.com/problems/find-median-from-data-stream/
*/
/*
  Solution: 
  https://zxi.mytechroad.com/blog/leetcode/leetcode-295-find-median-from-data-stream/
  add(num): O(logn)

  findMedian(): O(logn)
*/

import { PriorityQueue } from "./PriorityQueue";

class MedianFinder {
  private smaller: PriorityQueue<number>; // max-heap
  private larger: PriorityQueue<number>; // min-heap

  constructor() {
    this.smaller = new PriorityQueue<number>((a, b) => a > b);
    this.larger = new PriorityQueue<number>((a, b) => a < b);
  }

  // Time complexity: O(logn)
  // if num <= this.smaller.peek()!, add to this.smaller
  addNum(num: number): void {
    if (this.smaller.size() === 0 || num <= this.smaller.peek()!) {
      this.smaller.add(num);
      this.balanceHeaps();
    } else {
      this.larger.add(num);
      this.balanceHeaps();
    }
  }

  findMedian(): number {
    if (this.smaller.size() > this.larger.size()) {
      return this.smaller.peek()!;
    } else {
      return (this.smaller.peek()! + this.larger.peek()!) / 2;
    }
  }

  private balanceHeaps(): void {
    if (this.smaller.size() > this.larger.size() + 1) {
      this.larger.add(this.smaller.poll()!);
    } else if (this.larger.size() > this.smaller.size()) {
      this.smaller.add(this.larger.poll()!);
    }
  }
}
