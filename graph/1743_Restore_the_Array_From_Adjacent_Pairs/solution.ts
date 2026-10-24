/*
1743. Restore the Array From Adjacent Pairs

https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
*/

function restoreArray(adjacentPairs: number[][]): number[] {
  const n: number = adjacentPairs.length + 1;
  const g: Map<number, number[]> = new Map();

  for (const [a, b] of adjacentPairs) {
    if (!g.has(a)) {
      g.set(a, []);
    }
    if (!g.has(b)) {
      g.set(b, []);
    }
    g.get(a)!.push(b);
    g.get(b)!.push(a);
  }

  const ans: number[] = new Array(n);
  // Find the starting element which is the one with only one neighbor
  for (const [key, value] of g.entries()) {
    if (value.length === 1) {
      ans[0] = key;
      ans[1] = value[0];
      break;
    }
  }

  for (let i = 2; i < n; ++i) {
    // Access the neighbors of the last added element
    const v = g.get(ans[i - 1])!;
    // The next element is the one which is not the previously added element
    ans[i] = v[1] === ans[i - 2] ? v[0] : v[1];
  }

  return ans;
}
