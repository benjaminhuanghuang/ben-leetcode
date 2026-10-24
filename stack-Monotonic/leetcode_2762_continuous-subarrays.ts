/*
2762. Continuous Subarrays

https://leetcode.com/problems/continuous-subarrays/
*/

/*

*/
function countSubarrays(nums: number[]): number {
  const n = nums.length;
  let left = 0;
  let right = 0;
  let result = 0;

  const minDeque: number[] = []; // To store indices of minimum values
  const maxDeque: number[] = []; // To store indices of maximum values

  while (right < n) {
    // Maintain minDeque for minimum values
    while (
      minDeque.length &&
      nums[minDeque[minDeque.length - 1]] >= nums[right]
    ) {
      minDeque.pop();
    }
    // Maintain maxDeque for maximum values
    while (
      maxDeque.length &&
      nums[maxDeque[maxDeque.length - 1]] <= nums[right]
    ) {
      maxDeque.pop();
    }

    minDeque.push(right);
    maxDeque.push(right);

    // Ensure the max - min <= 2
    while (nums[maxDeque[0]] - nums[minDeque[0]] > 2) {
      left++;
      if (minDeque[0] < left) {
        minDeque.shift();
      }
      if (maxDeque[0] < left) {
        maxDeque.shift();
      }
    }

    result += right - left + 1;
    right++;
  }

  return result;
}
