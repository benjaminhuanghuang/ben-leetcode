/*
    Find the number of subarrays in an integer array that sum to k.
    
    prefixSum[i] = nums[0] + nums[1] + ... + nums[i]
    sum(i..j) = prefixSum[j] - prefixSum[i - 1]
    to find sum(i..j) = k, we need prefixSum[j] - prefixSum[i - 1] = k
    => prefixSum[i - 1] = prefixSum[j] - k

    When we reach a certain prefixSum[j], as long as there has been a previous prefix sum equal to (prefixSum[j] - k),
    then the subarray from that position to the current position has a sum of k.
    
    用“前缀和”把子数组求和问题转化为“两个前缀和的差值问题”，
*/

function k_sum_subarrays_optimized(nums: number[], k: number): number {
  let count = 0;

  // Initialize the map with 0 to handle subarrays that sum to 'k'
  // from the start of the array.
  // 每个前缀和出现的次数
  const prefixSumMap = new Map<number, number>([[0, 1]]);
  let currPrefixSum = 0;

  for (const num of nums) {
    // Update the running prefix sum by adding the current number.
    currPrefixSum += num;

    // If a subarray with sum 'k' exists, increment 'count' by the
    // number of times it has been found.
    if (prefixSumMap.has(currPrefixSum - k)) {
      // find number of previous prefix sums that equal currPrefixSum - k
      count += prefixSumMap.get(currPrefixSum - k) || 0;
    }

    // Update the frequency of 'currPrefixSum' in the hash map.
    const freq = prefixSumMap.get(currPrefixSum) || 0;
    prefixSumMap.set(currPrefixSum, freq + 1);
  }

  return count;
}
/*
Time complexity: The time complexity of k_sum_subarrays_optimized is O(n) because we iterate
through each value in the nums array.

Space complexity: The space complexity is O(n) due to the space taken up by the hash map.
*/
