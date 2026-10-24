// (row1, col1) and (row2, col2) are on the same diagonal
const col1 = 1,
  row1 = 1,
  col2 = 1,
  row2 = 1;
// the angle is 45 degree
const attack = Math.abs(col1 - col2) === Math.abs(row1 - row2);

/*--------------------------------------------*/
// cell is on the diagonal
// Main Diagonal Check (Top-left to Bottom-right)：row - col 的值相等
// Anti-Diagonal Check (Top-right to Bottom-left)：row + col 的值相等
/*--------------------------------------------*/
const rows = 3,
  cols = 3;
const row = 1,
  col = 1;
if (row == col || row == cols - 1 - col) {
  // on the diagonal
}

// N*N matrix
function create2DMatrix(
  rows: number,
  cols: number,
  defaultValue: number
): number[][] {
  return Array.from({ length: rows }).map(() =>
    Array.from({ length: cols }).map(() => defaultValue)
  );
}

export {};
