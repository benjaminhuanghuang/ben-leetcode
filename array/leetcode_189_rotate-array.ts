/*
189. Rotate Array

https://leetcode.com/problems/rotate-array/

rotate the array to the right by k steps, where k is non-negative.
*/

function rotate(nums: number[], k: number): void {
  k %= nums.length;
  reverse(nums, 0, nums.length - 1); // reverse the whole array
  reverse(nums, 0, k - 1); // reverse the first k elements
  reverse(nums, k, nums.length - 1); // reverse the rest elements
}

function reverse(nums: number[], start: number, end: number): void {
  while (start < end) {
    [nums[start], nums[end]] = [nums[end], nums[start]];
    start++;
    end--;
  }
}
