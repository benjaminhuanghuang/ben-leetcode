/*
3026. Maximum Good Subarray Sum

https://leetcode.com/problems/maximum-good-subarray-sum/

the subarray nums[i..j] is good if |nums[i] - nums[j]| == k.
*/

function maximumSubarraySum(nums: number[], k: number): number {
  // Initialize a map to keep track of prefix sums and their indices
  const prefixSumIndices: Map<number, number> = new Map();
  prefixSumIndices.set(0, -1);

  let maxSum: number = Number.MIN_SAFE_INTEGER;

  // Initialize summation variable to keep track of the running sum
  let sum: number = 0;

  // Loop through the array
  for (let i = 0; i < nums.length; ++i) {
    // Add current number to the running sum
    sum += nums[i];

    // Check if there's a prefix sum such that current sum - previous sum equals to k
    if (prefixSumIndices.has(sum - k)) {
      // Update maxSum with the largest sum found so far
      maxSum = Math.max(maxSum, sum - prefixSumIndices.get(sum - k)!);
    }

    // If this sum has not been seen before or the previous index is greater,
    // update the map with the current index for this sum.
    // This helps in finding the smallest index (leftmost) for this prefixSum
    if (!prefixSumIndices.has(sum) || prefixSumIndices.get(sum)! > i) {
      prefixSumIndices.set(sum, i);
    }
  }

  // If maxSum was not updated, there's no valid subarray sum; return 0. Otherwise, return maxSum.
  return maxSum === Number.MIN_SAFE_INTEGER ? 0 : maxSum;
}
