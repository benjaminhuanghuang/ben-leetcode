/*
1043. Partition Array for Maximum Sum

https://leetcode.com/problems/partition-array-for-maximum-sum/
*/

/*
https://www.youtube.com/watch?v=3M8q-wB2tmw (HuaHua)

*/
function maxSumAfterPartitioning(arr: number[], k: number): number {
  const n: number = arr.length;
  // Initialize an array to store the maximum sum of subarrays up to each index
  const dp: number[] = new Array(n + 1).fill(0);

  for (let i = 1; i <= n; ++i) {
    let maxElement: number = 0; // Variable to keep track of the max element in the current partition
    // Check all possible partitions up to the length 'k'
    for (let j = i; j > Math.max(0, i - k); --j) {
      maxElement = Math.max(maxElement, arr[j - 1]); // Update max element of the current partition
      // Update the dp array with the maximum sum by comparing the existing sum and
      // the new sum formed by adding the max element multiplied by the partition size
      dp[i] = Math.max(dp[i], dp[j - 1] + maxElement * (i - j + 1));
    }
  }
  return dp[n];
}
