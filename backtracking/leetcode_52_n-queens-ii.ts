/*
52. N-Queens II
https://leetcode.com/problems/n-queens-ii/

*/

function totalNQueens(n: number): number {
  let count = 0;

  function dfs(n: number, row: number, cur: number[]) {
    if (row === n) {
      // exceed the last row, find a answer
      count++;
      return;
    }

    for (let col = 0; col < n; col++) {
      if (isValid(cur, row, col, n)) {
        cur.push(col);
        dfs(n, row + 1, cur);
        cur.pop();
      }
    }
  }

  function isValid(
    board: number[],
    row: number,
    col: number,
    n: number
  ): boolean {
    for (let i = 0; i < row; i++) {
      // check the queens in the previous rows
      if (board[i] === col) return false;
      // the angle is 45 degree
      if (Math.abs(board[i] - col) === Math.abs(i - row)) return false;
    }
    return true;
  }

  // [] is the current board, [row] is the col of the queen
  dfs(n, 0, []); // start from row 0 with empty board

  return count;
}
