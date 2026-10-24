/*
Q: Find the minimum length subarray, where the sum is greater than or equal to the target. 
Assume all values are positive.
*/

// Find length of minimum size subarray where the sum is
// greater than or equal to the target: O(n)
function shortestSubarray(nums: number[], target: number): number {
  let l = 0;
  let total = 0;
  let length = Infinity;

  for (let r = 0; r < nums.length; r++) {
    total += nums[r]; // the window is [l, r]
    while (total >= target) {
      length = Math.min(r - l + 1, length);
      total -= nums[l];
      l++;
    }
  }

  return length === Infinity ? 0 : length;
}
