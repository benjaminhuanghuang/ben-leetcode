/*

N-Queens


Talk-through: Backtracking, placing one queen per row. Track occupied
columns and both diagonals (col - row and col + row each identify a unique
diagonal) in sets for O(1) conflict checks instead of rescanning the board.
A full placement is found once every row has a queen.

Time big O of n!, space big O of n for the recursion stack and tracking sets.
*/
function solveNQueens(n: number): string[][] {
  const result: string[][] = [];
  const cols = new Set<number>();
  const diag1 = new Set<number>();
  const diag2 = new Set<number>();
  const queenCol: number[] = [];

  function backtrack(row: number): void {
    if (row === n) {
      const board = queenCol.map((col) => {
        return ".".repeat(col) + "Q" + ".".repeat(n - col - 1);
      });
      result.push(board);
      return;
    }

    for (let col = 0; col < n; col++) {
      if (cols.has(col) || diag1.has(col - row) || diag2.has(col + row)) {
        continue;
      }

      cols.add(col);
      diag1.add(col - row);
      diag2.add(col + row);
      queenCol.push(col);

      backtrack(row + 1);

      cols.delete(col);
      diag1.delete(col - row);
      diag2.delete(col + row);
      queenCol.pop();
    }
  }

  backtrack(0);
  return result;
}
