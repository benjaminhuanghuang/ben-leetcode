/*
216. Combination Sum III

https://leetcode.com/problems/combination-sum-iii/
*/

/*
  https://zxi.mytechroad.com/blog/searching/leetcode-216-combination-sum-iii/


  Time complexity: C(m, k) = C(9, k) = 9!/k!/(9-ks)
  Space complexity: O(k + k*# of ans)
*/
function combinationSum3(k: number, n: number): number[][] {
  const ans: number[][] = [];
  const cur: number[] = [];

  dfs(k, n, 1, cur, ans);
  return ans;
}

function dfs(
  k: number,
  sum: number,
  start: number,
  cur: number[],
  ans: number[][]
): void {
  if (k === 0 && sum === 0) {
    ans.push([...cur]);
    return;
  }

  for (let i = start; i <= 9; ++i) {
    if (i > sum) {
      return;
    }
    cur.push(i);
    dfs(k - 1, sum - i, i + 1, cur, ans);
    cur.pop();
  }
}
