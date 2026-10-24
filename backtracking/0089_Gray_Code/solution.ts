/*
89. Gray Code

https://leetcode.com/problems/gray-code/
*/

function grayCode(n: number): number[] {
  const res: number[] = [];
  const set: Set<number> = new Set();
  dfs(n, set, 0, res);
  return res;
}

function dfs(n: number, set: Set<number>, curr: number, res: number[]): void {
  if (!set.has(curr)) {
    set.add(curr);
    res.push(curr);
  }

  for (let i = 0; i < n; ++i) {
    let t = curr;
    if ((t & (1 << i)) === 0) {
      t |= 1 << i; // Set the i-th bit to 1
    } else {
      t &= ~(1 << i); // Set the i-th bit to 0
    }

    if (set.has(t)) continue;
    dfs(n, set, t, res);
    break;
  }
}
