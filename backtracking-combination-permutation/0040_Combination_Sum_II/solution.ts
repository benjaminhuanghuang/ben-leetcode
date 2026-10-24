/*
40. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/

Note: The solution set must not contain duplicate combinations.
Each number in candidates may only be used once in the combination.

*/

/*
HuaHua
https://www.youtube.com/watch?v=RSatA4uVBDQ

Template for combination problem:
C(nums, depth, count of elements in one answer, start index, curr, ans)

Hit: how to avoid duplicate answer like [1, 7] and [another 1, 7]?
    - Add each answer to a set, and then convert the set to an array finally
    - Disallow smame number to be used in the same depth

Time complexity: O(2^n), each number has two choices: use or not use
Space complexity: O(kn)  K is the number of answers, N is the length of the answer
*/

/*
Disallow same number to be used in the same depth
*/
function combinationSum2(candidates: number[], target: number): number[][] {
  // for pruning
  candidates.sort((a, b) => a - b);

  let ans: number[][] = [];
  let cur: number[] = [];

  function dfs(
    candidates: number[],
    target: number,
    s: number,
    cur: number[],
    ans: number[][]
  ) {
    if (target === 0) {
      ans.push([...cur]); // 必须拷贝！
      return;
    }

    for (let i = s; i < candidates.length; i++) {
      if (candidates[i] > target) break; // pruning by sorting the array
      // Disallow same number to be used in the same depth. 只允许第一个重复数字进入当前层，而第二个直接跳过
      if (i > s && candidates[i] === candidates[i - 1]) continue;
      cur.push(candidates[i]);
      dfs(candidates, target - candidates[i], i + 1, cur, ans); // use i + 1, because Each number in candidates may only be used once in the combination.
      cur.pop();
    }
  }

  dfs(candidates, target, 0, cur, ans);

  return ans;
}

/*
Use set, TLE
*/
function combinationSum2_TLE(candidates: number[], target: number): number[][] {
  // for pruning
  candidates.sort((a, b) => a - b);

  let ans: Set<string> = new Set();
  let cur: number[] = [];

  dfs(candidates, target, 0, cur, ans);

  return Array.from(ans).map((combination) => JSON.parse(combination));
}

function dfs(
  candidates: number[],
  target: number,
  s: number,
  cur: number[],
  ans: Set<string>
) {
  if (target === 0) {
    ans.add(JSON.stringify([...cur]));
    return;
  }

  for (let i = s; i < candidates.length; i++) {
    if (candidates[i] > target) break; // pruning by sorting the array

    cur.push(candidates[i]);
    dfs(candidates, target - candidates[i], i + 1, cur, ans); // use i + 1, because Each number in candidates may only be used once in the combination.
    cur.pop();
  }
}

/*
https://www.youtube.com/watch?v=rSA3t6BDDwg


*/

export {};
