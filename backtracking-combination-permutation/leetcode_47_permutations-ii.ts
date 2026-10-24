/*
47. Permutations II

https://leetcode.com/problems/permutations-ii/


The array might contain duplicates

核心区别就是 排序 + 判断前一个重复数字是否已用 来保证不产生重复排列。
*/

/*
https://zxi.mytechroad.com/blog/searching/leetcode-47-permutations-ii/

Time complexity: O(n!)
Space complexity: O(n + k)
时间复杂度：递归被调用的次数与解的个数一样是n!次，每次有个for循环，那么总时间复杂度是O(n*n!)
空间复杂度：与调用递归次数一样O(n!)

The duplicate case
  1       1       2     --- 对于这一层的第二个1，`不应该`使用，此时第一个1，visited[i-1] = false
1   2   1   2   1   1   --- 对于这一层的第二个1，`可以`再使用，此时第一个1，visited[i-1] = true
2   1   2   1   1   1

*/

function permuteUnique(nums: number[]): number[][] {
  const ans: number[][] = [];
  const cur: number[] = [];
  const used: boolean[] = Array(nums.length).fill(false);
  nums.sort((a, b) => a - b); // 和46 的不同， 把相同的数字挨在一起

  permute_dfs(nums, cur, ans, used);

  return ans;
}
/*
    No start index, because we need to use all the elements
*/
function permute_dfs(
  nums: number[],
  cur: number[],
  ans: number[][],
  used: boolean[]
): void {
  const n = nums.length;
  if (cur.length === n) {
    ans.push([...cur]);
    return;
  }
  // Always from 0
  for (let i = 0; i < n; ++i) {
    // 和46的不同
    // Same number can be only used once at each depth.
    // 如果两个相同的数字在"同一个选择层"，我们只让第一个被选择，强制跳过第二个， 如果前面有个相同的数还没用，说明我们在"同一层"选择，必须先用前面那个
    // 在同一层递归中，不允许后面的重复数字先于前面的重复数字被使用。
    // 如果 used[i-1] = true，说明前一个相同的数已经被用在当前路径中了，现在是在更深的递归层，可以用后一个， 否则就是在同一层，跳过后一个
    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
    if (used[i]) continue;

    used[i] = true;
    cur.push(nums[i]);

    permute_dfs(nums, cur, ans, used);

    cur.pop();
    used[i] = false;
  }
}

export { permuteUnique };
