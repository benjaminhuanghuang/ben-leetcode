/*
2461. Maximum Sum of Distinct Subarrays With Length K

https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
*/

/*
    Approach: Brute Force
    Time complexity: O(n * k)
*/
function findMaxSumOfSequence_BF(
  listOfItems: number[],
  sequenceLength: number
) {
  if (listOfItems.length < sequenceLength) {
    return null;
  }

  let maxSum = -Infinity;
  for (let i = 0; i <= listOfItems.length - sequenceLength; i++) {
    let sum = 0;
    for (let j = i; j < i + sequenceLength; j++) {
      sum += listOfItems[j];
    }
    maxSum = Math.max(maxSum, sum);
  }

  return maxSum;
}

/*
    Approach: Sliding Window
    Update maxSum when the current subarray has 'k' distinct elements
    
    Time complexity: O(n)

*/

function maximumSubarraySum(nums: number[], k: number): number {
  const n: number = nums.length;
  const countMap: Map<number, number> = new Map();
  let windowSum: number = 0;

  // Initialize the count map and current sum with the first 'k' elements
  for (let i: number = 0; i < k; ++i) {
    countMap.set(nums[i], (countMap.get(nums[i]) ?? 0) + 1);
    windowSum += nums[i];
  }

  // Check if the first subarray of length 'k' has 'k' distinct numbers
  let maxSum: number = countMap.size === k ? windowSum : 0;

  for (let i: number = k; i < n; ++i) {
    // Add the next number to the count map and current sum
    countMap.set(nums[i], (countMap.get(nums[i]) ?? 0) + 1);
    windowSum += nums[i];

    // Remove the starting element of the window
    const prevCount: number = countMap.get(nums[i - k])! - 1;
    countMap.set(nums[i - k], prevCount);
    windowSum -= nums[i - k];

    // If after decrementing, the count is zero, remove it from the map
    if (prevCount === 0) {
      countMap.delete(nums[i - k]);
    }

    // If the current subarray has 'k' distinct elements, update maxSum
    if (countMap.size === k) {
      maxSum = Math.max(maxSum, windowSum);
    }
  }

  return maxSum;
}
