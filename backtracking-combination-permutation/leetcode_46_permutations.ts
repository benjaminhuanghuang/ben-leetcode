/*
46. Permutations

https://leetcode.com/problems/permutations/

The numbers in the array are all distinct.
*/

/*
use Huahua's template
https://www.youtube.com/watch?v=CUzm-buvH_8
https://zxi.mytechroad.com/blog/searching/leetcode-46-permutations/

Time complexity: O(n!)
Space complexity: O(n)
*/

function permute(nums: number[]): number[][] {
  const ans: number[][] = [];
  const cur: number[] = [];
  // used 用来保证每个元素只使用一次
  const used: boolean[] = Array(nums.length).fill(false);

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
    // i is the start index
    if (used[i]) continue;
    used[i] = true;
    cur.push(nums[i]);
    permute_dfs(nums, cur, ans, used);
    cur.pop();
    used[i] = false;
  }
}
