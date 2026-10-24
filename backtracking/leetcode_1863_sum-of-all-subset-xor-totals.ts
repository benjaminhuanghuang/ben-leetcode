/*
1863. Sum of All Subset XOR Totals

https://leetcode.com/problems/sum-of-all-subset-xor-totals/

Given an array nums, return the sum of all XOR totals for every subset of nums. 

[Meta]
*/

/*
https://algo.monster/liteproblems/1863

Time Complexity: O(2^N)  2^N subsets
Space Complexity: O(N)  recursion stack
*/
function subsetXORSum(nums: number[]): number {
  let results: number[] = []; // To store XOR of all subsets
  let currentXOR = 0; // Current XOR value at any point of DFS traversal
  dfs(nums, 0, currentXOR, results);

  // Sum up and return all XOR values from the results array
  return results.reduce(
    (accumulator, currentValue) => accumulator + currentValue,
    0
  );
}

function dfs(
  nums: number[],
  start: number,
  currentXOR: number,
  results: number[]
): void {
  results.push(currentXOR); // Add the current XOR to the results array

  // Explore further subsets by including elements one by one
  for (let i = start; i < nums.length; i++) {
    currentXOR ^= nums[i]; // Include nums[i] in the current subset and update the XOR
    dfs(nums, i + 1, currentXOR, results); // Recur for next elements

    // Backtrack: remove nums[i] from the current subset and revert the XOR
    currentXOR ^= nums[i];
  }
}

export {};
