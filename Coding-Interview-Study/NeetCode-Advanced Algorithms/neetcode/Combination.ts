/*

Combinations
Q: Given two nums n & k, return all possible combinations of size=k, choosing from values between 1 and n.

O(k⋅C(n,k))
*/
function combine(n: number, k: number): number[][] {
  const res: number[][] = [];
  const path: number[] = [];

  function dfs(start: number) {
    if (path.length === k) {
      res.push([...path]);
      return;
    }

    for (let i = start; i <= n; i++) {
      path.push(i);
      dfs(i + 1); // 下一轮从 i+1 开始
      path.pop();
    }
  }

  dfs(1);
  return res;
}

function combine2(n: number, k: number): number[][] {
  const ans: number[][] = [];

  const backtracking = (start: number, curr: number[]) => {
    if (curr.length == k) {
      ans.push([...curr]);
      return;
    }

    // i is the index
    for (let i = start; i < n; i++) {
      curr.push(i + 1);
      backtracking(i + 1, curr);
      curr.pop();
    }
  };

  backtracking(0, []);

  return ans;
}
