/*
2824. Count Pairs Whose Sum is Less than Target

https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
*/

function countPairs(nums: number[], target: number): number {
  nums.sort((a, b) => a - b);
  let pairCount = 0; // Initialize the count of pairs.

  // A binary search function to find the index of the smallest number in 'nums'
  // that is greater than or equal to 'x', up to but not including index 'rightLimit'.
  function binarySearch(x: number, rightLimit: number): number {
    let left = 0;
    let right = rightLimit;
    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (nums[mid] >= x) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    // Return the index of the smallest number greater than or equal to 'x'.
    return left;
  }

  // Iterate through the sorted array to find all pairs that meet the condition.
  for (let j = 0; j < nums.length; ++j) {
    // Use the binary search function to find the number of elements
    // that can be paired with 'nums[j]' to be less than the 'target'.
    const index = binarySearch(target - nums[j], j);
    // Add the number of valid pairs to 'pairCount'.
    pairCount += index;
  }

  // Return the total count of valid pairs.
  return pairCount;
}
