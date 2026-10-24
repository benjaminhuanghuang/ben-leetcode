/*
347. Top K Frequent Elements

https://leetcode.com/problems/top-k-frequent-elements/

692. Top K Frequent Words
*/

import { PriorityQueue } from "./PriorityQueue";

function topKFrequent(nums: number[], k: number): number[] {
  // count the frequency of each element
  const map = new Map<number, number>();
  for (let num of nums) {
    map.set(num, (map.get(num) || 0) + 1);
  }
  // create a min heap, order by frequency,
  // the min one will be popped when the heap is full
  const pq = new PriorityQueue<number[]>((a, b) => a[1] < b[1]);

  for (let [num, freq] of map.entries()) {
    pq.add([num, freq]);
    if (pq.size() > k) {
      pq.poll();
    }
  }
  const ans: number[] = [];
  for (let i = 0; i < k; i++) {
    ans.push(pq.poll()![0]);
  }
  return ans;
}
