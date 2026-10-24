/*
39. Combination Sum
https://leetcode.com/problems/combination-sum/

每个元素可以重复使用，顺序不同但数字相同的组合视为同一个结果
*/

/*
https://www.youtube.com/watch?v=zIY2BWdsbFs

combination problem,
Need sort
*/
function combinationSum(candidates: number[], target: number): number[][] {
  // for pruning， 一旦当前 candidate 已经大于剩余 target，可以直接结束循环，因为后面的数字更大，不可能再组成目标值。
  candidates.sort((a, b) => a - b);

  let ans: number[][] = [];
  let cur: number[] = [];

  function dfs(
    candidates: number[],
    target: number,
    s: number, // 当前搜索起点 index，用于避免排列重复
    cur: number[],
    ans: number[][]
  ) {
    if (target === 0) {
      ans.push([...cur]);
      return;
    }

    for (let i = s; i < candidates.length; i++) {
      if (candidates[i] > target) break; // pruning by sorting the array

      cur.push(candidates[i]);
      dfs(candidates, target - candidates[i], i, cur, ans); // use i: not i + 1, because we can reuse the same element
      cur.pop();
    }
  }

  dfs(candidates, target, 0, cur, ans);

  return ans;
}

function combinationSum_faster(
  candidates: number[],
  target: number
): number[][] {
  function bfs(cur: number[], sum: number, index: number): void {
    if (sum === target) {
      res.push(cur);
      return;
    }
    if (sum > target) return;

    for (let i = index; i < candidates.length; i++) {
      //创建新数组，无需 cur.pop()，但频繁创建新数组带来开销
      bfs([...cur, candidates[i]], sum + candidates[i], i);
    }
  }
  const res: number[][] = [];
  bfs([], 0, 0);
  return res;
}
