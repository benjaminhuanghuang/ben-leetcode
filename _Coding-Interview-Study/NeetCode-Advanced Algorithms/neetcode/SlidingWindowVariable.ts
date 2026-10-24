/*
Q: Find the length of the longest subarray, with the same value in each position.
*/

// Find the length of longest subarray with the same
// value in each position: O(n)
function longestSubarray(nums: number[]): number {
  let length = 0;
  let l = 0;

  for (let r = 0; r < nums.length; r++) {
    if (nums[l] !== nums[r]) {
      l = r;
    }
    length = Math.max(length, r - l + 1);
  }

  return length;
}
