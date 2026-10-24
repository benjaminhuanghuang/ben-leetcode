/*
692. Top K Frequent Words

https://leetcode.com/problems/top-k-frequent-words/
*/

/*
    Approach priority_queue 
   
    Huahua
    https://www.youtube.com/watch?v=POERw4yDVBw
    http://zxi.mytechroad.com/blog/heap/leetcode-692-top-k-frequent-words/

   O(n log k) / O(n)
*/

import { PriorityQueue } from "./PriorityQueue";

function topKFrequent(words: string[], k: number): string[] {
  const count: Map<string, number> = new Map();

  // Count frequencies
  for (const word of words) {
    count.set(word, (count.get(word) || 0) + 1);
  }

  // Custom comparator function for priority queue
  const comparator = (a: [string, number], b: [string, number]): boolean => {
    if (a[1] === b[1]) {
      return a[0].localeCompare(b[0]) < 0; // Order by alphabet ASC
    }
    return a[1] < b[1]; // Order by frequency DESC
  };

  // O(n*logk)
  const pq: PriorityQueue<[string, number]> = new PriorityQueue(comparator, k);
  for (const [word, freq] of count.entries()) {
    pq.add([word, freq]);
  }

  // Extract results from priority queue
  const ans: string[] = [];
  while (pq.size() > 0) {
    ans.unshift(pq.poll()![0]); // Reverse order to get highest frequency first
  }

  return ans;
}
