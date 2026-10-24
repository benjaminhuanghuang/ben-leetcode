function maximumSubarraySumDPOptimized(nums: number[]): number {
  const n = nums.length;
  if (n === 0) return 0;

  let currentSum = nums[0];
  let maxSum = nums[0];

  for (let i = 1; i < n; i++) {
    // Either extend the current subarray or start a new one at nums[i]
    currentSum = Math.max(nums[i], currentSum + nums[i]);
    maxSum = Math.max(maxSum, currentSum);
  }

  return maxSum;
}

/*
space complexity to 0(1).
*/
