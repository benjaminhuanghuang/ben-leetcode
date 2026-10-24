/*
373. Find K Pairs with Smallest Sums

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

nums1 and nums2 sorted in non-decreasing order

*/
import { PriorityQueue } from "./PriorityQueue";

type PairNode = {
  sum: number; // sum of nums1[i1] + nums2[i2]
  i1: number; // index of nums1[i1]
  i2: number; // index of nums2[i2]
};
function kSmallestPairs(
  nums1: number[],
  nums2: number[],
  k: number
): number[][] {
  const ans: number[][] = [];
  if (nums1.length === 0 || nums2.length === 0) return ans;

  const minHeap = new PriorityQueue<PairNode>((a, b) => a.sum < b.sum);
  // 将nums1中每个数和nums2的第一个数放进堆
  for (let i = 0; i < k && i < nums1.length; ++i) {
    minHeap.add({
      sum: nums1[i] + nums2[0],
      i1: i,
      i2: 0,
    });
  }
  // If need more, add the sum of the next element in nums2
  // k <= nums1.length * nums2.length
  while (k-- && !minHeap.isEmpty()) {
    const minNode = minHeap.poll();
    if (minNode) {
      ans.push([nums1[minNode.i1], nums2[minNode.i2]]);
      if (minNode.i2 + 1 < nums2.length) {
        minHeap.add({
          sum: nums1[minNode.i1] + nums2[minNode.i2 + 1],
          i1: minNode.i1,
          i2: minNode.i2 + 1,
        });
      }
    }
  }

  return ans;
}
