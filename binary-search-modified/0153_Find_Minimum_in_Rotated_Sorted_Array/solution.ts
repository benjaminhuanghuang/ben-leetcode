/*
153. Find Minimum in Rotated Sorted Array

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

*/

/*
https://www.youtube.com/watch?v=P4r7mF1Jd50 (Hua Hua)
Time complexity:

T(n) = O(1) + T(n/2) = O(logn)
*/
function findMin(nums: number[]): number {
  return findMinHelper(nums, 0, nums.length - 1);
}

function findMinHelper(nums: number[], l: number, r: number): number {
  // Only 1 or 2 elements
  if (l + 1 >= r) return Math.min(nums[l], nums[r]);

  // left < right means this section is sorted, Important!
  if (nums[l] < nums[r]) return nums[l];

  const mid = l + Math.floor((r - l) / 2);

  return Math.min(findMinHelper(nums, l, mid - 1), findMinHelper(nums, mid, r));
}

export {};
