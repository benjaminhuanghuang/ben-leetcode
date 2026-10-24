/*
Permutations
Q: Given a list of nums, return all possible distinct permutations of nums.
*/
// Time: O(n^2 * n!)
// Level 1, n choices, Level 2, n-1 choices, ..., Level n, 1 choice
// At each leaf node, we do [...path] which costs O(n) to copy.
function permuteUnique(nums: number[]): number[][] {
  nums.sort((a, b) => a - b); // 排序处理重复

  const res: number[][] = [];
  const path: number[] = [];
  const used: boolean[] = new Array(nums.length).fill(false);

  function dfs() {
    if (path.length === nums.length) {
      res.push([...path]);
      return;
    }

    for (let i = 0; i < nums.length; i++) {
      if (used[i]) continue; // 已使用
      // 去重：同一层相同数字只能选一次
      if (i > 0 && nums[i] === nums[i - 1] && !used[i - 1]) continue;

      used[i] = true;
      path.push(nums[i]);
      dfs();
      path.pop();
      used[i] = false;
    }
  }

  dfs();
  return res;
}
