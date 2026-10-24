/*
Find the number of subarrays in an integer array that sum to k.
*/

function k_sum_subarrays(nums: number[], k: number): number {
  const n = nums.length;
  let count = 0;

  // Populate the prefix sum array, setting its first element to 0.
  const prefixSum: number[] = [0];
  for (let i = 0; i < n; i++) {
    prefixSum.push(prefixSum[prefixSum.length - 1] + nums[i]);
  }

  // Loop through all valid pairs of prefix sum values to find all
  // subarrays that sum to 'k'.
  for (let j = 1; j <= n; j++) {
    for (let i = 1; i <= j; i++) {
      if (prefixSum[j] - prefixSum[i - 1] === k) {
        count += 1;
      }
    }
  }

  return count;
}

/*
time complexity to O(n^2).
*/
