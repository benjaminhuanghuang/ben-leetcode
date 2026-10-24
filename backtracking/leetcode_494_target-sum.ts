/*
494. Target Sum

https://leetcode.com/problems/target-sum/
*/

/*

  DFS

  Time complexity: O(2^n)

  Space complexity: O(n)

*/
function findTargetSumWays(nums: number[], S: number): number {
  const sum = nums.reduce((acc, num) => acc + num, 0);
  if (sum < Math.abs(S)) return 0;
  let ans = { value: 0 };
  dfs(nums, 0, S, ans);

  return ans.value;
}

function dfs(
  nums: number[],
  digits: number,
  sum: number,
  ans: { value: number }
): void {
  if (digits === nums.length) {
    if (sum === 0) ++ans.value;
    return;
  }
  dfs(nums, digits + 1, sum - nums[digits], ans);
  dfs(nums, digits + 1, sum + nums[digits], ans);
}

export {};
