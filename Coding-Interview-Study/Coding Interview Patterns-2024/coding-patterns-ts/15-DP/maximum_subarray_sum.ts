function maximumSubarraySum(nums: number[]): number {
  if (nums.length === 0) return 0;

  let maxSum = -Infinity;
  let currentSum = -Infinity;

  for (const num of nums) {
    // Either extend the current subarray or start a new one
    currentSum = Math.max(currentSum + num, num);
    maxSum = Math.max(maxSum, currentSum);
  }

  return maxSum;
}

/*
Time complexity: The time complexity of maximum_subarray_sum is O(n) because we iterate
through each element of the input array once.

Space complexity: The space complexity is O(1).
*/
