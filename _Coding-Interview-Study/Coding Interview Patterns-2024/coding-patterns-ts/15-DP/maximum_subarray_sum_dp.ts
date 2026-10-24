function maximumSubarraySumDP(nums: number[]): number {
  const n = nums.length;
  if (n === 0) return 0;

  const dp: number[] = new Array(n).fill(0);

  // Base case: maximum subarray ending at first element
  dp[0] = nums[0];
  let maxSum = dp[0];

  // Populate the DP array
  for (let i = 1; i < n; i++) {
    dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
    maxSum = Math.max(maxSum, dp[i]);
  }

  return maxSum;
}
/*
Time complexity: The time complexity of maximum_subarray_sum_dp is O(n) since we iterate
through n elements of the DP array.

Space complexity: The space complexity is O(n) because we're maintaining a DP array that contains
n elements.
*/
