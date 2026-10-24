/*
78. Subsets

https://leetcode.com/problems/subsets/description/

90. Subsets II
*/

/*
https://www.youtube.com/watch?v=CUzm-buvH_8

Use the HuaHua combination template
*/

function subsets(nums: number[]): number[][] {
  const ans: number[][] = [];

  // pick n numbers as a subset
  function backtrack(n: number, startPos: number, cur: number[]): void {
    if (n == cur.length) {
      ans.push([...cur]); // push a copy of cur to ans!
      return;
    }

    for (let i = startPos; i < nums.length; i++) {
      cur.push(nums[i]);
      backtrack(n, i + 1, cur);
      cur.pop();
    }
  }

  for (let i = 0; i <= nums.length; i++) {
    backtrack(i, 0, []); // i: length of the subset, startPos: 0, cur: []
  }

  return ans;
}

function subsets2(nums: number[]): number[][] {
  const res: number[][] = [];

  function backtrack(start: number, path: number[]) {
    res.push([...path]); // 每个路径都是一个子集

    for (let i = start; i < nums.length; i++) {
      path.push(nums[i]); // select nums[i]
      backtrack(i + 1, path); // 递归处理下一个元素
      path.pop(); // undo
    }
  }

  backtrack(0, []);
  return res;
}

export {};
