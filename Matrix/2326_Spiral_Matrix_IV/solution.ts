/*
2326. Spiral Matrix IV

https://leetcode.com/problems/spiral-matrix-iv/
*/

import { ListNode } from "../Common/ListNode";

function spiralMatrix(m: number, n: number, head: ListNode | null): number[][] {
  const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
  const dirs: number[] = [0, 1, 0, -1, 0];
  let [row, col, dir] = [0, 0, 0];

  while (1) {
    ans[row][col] = head!.val;
    head = head!.next;
    if (!head) {
      break;
    }
    while (1) {
      const [x, y] = [row + dirs[dir], col + dirs[dir + 1]];
      if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] === -1) {
        row = x;
        col = y;
        break;
      }
      dir = (dir + 1) % 4;
    }
  }
  return ans;
}
