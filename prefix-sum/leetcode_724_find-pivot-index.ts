/*
724. Find Pivot Index

https://leetcode.com/problems/find-pivot-index/
*/

function pivotIndex(nums: number[]): number {
  let sumLeft = 0; // Initialize sum of elements to the left
  let sumRight = nums.reduce((a, b) => a + b, 0);

  for (let i = 0; i < nums.length; ++i) {
    sumRight -= nums[i]; // Subtract the current element from the right sum
    if (sumLeft === sumRight) {
      return i;
    }

    sumLeft += nums[i];
  }

  return -1;
}
