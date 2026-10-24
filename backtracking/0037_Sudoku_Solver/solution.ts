/*
37. Sudoku Solver

https://leetcode.com/problems/sudoku-solver/

- 36. Valid Sudoku
- 51. N-Queens
- 52. N-Queens II
*/

/*
Hua Hua
https://www.youtube.com/watch?v=ucugbKwjtRs
https://zxi.mytechroad.com/blog/searching/leetcode-37-sudoku-solver/

DFS + back-tracking
*/

// // 表示某行，某列，某block是否包含数字 1 - 9, use 0 to 9 for convenience
let rows: number[][];
let cols: number[][];
let boxes: number[][];

function solveSudoku(board: string[][]): void {
  // Initialize rows, cols, and boxes
  rows = Array.from({ length: 9 }, () => Array(10).fill(0));
  cols = Array.from({ length: 9 }, () => Array(10).fill(0));
  boxes = Array.from({ length: 9 }, () => Array(10).fill(0));

  // Initialize rows, cols, and boxes
  for (let row = 0; row < 9; row++) {
    for (let col = 0; col < 9; col++) {
      const c = board[row][col];
      if (c !== ".") {
        const n = parseInt(c);
        const bx = Math.floor(col / 3);
        const by = Math.floor(row / 3);
        // Set n to used
        rows[row][n] = 1;
        cols[col][n] = 1;
        boxes[by * 3 + bx][n] = 1;
      }
    }
  }

  dfsFill(board, 0, 0);
}

function dfsFill(board: string[][], row: number, col: number): boolean {
  if (row === 9) return true; // row index [0-8] out of bounds

  // Next cell
  const nCol = (col + 1) % 9;
  const nRow = nCol === 0 ? row + 1 : row; // Move to next row if col is 9

  if (board[row][col] !== ".") {
    // current cell is filled
    return dfsFill(board, nRow, nCol);
  }

  // Try filling number 1 to 9 in current cell
  for (let i = 1; i <= 9; i++) {
    const bx = Math.floor(col / 3);
    const by = Math.floor(row / 3);
    const boxKey = by * 3 + bx;

    // Validate
    if (!rows[row][i] && !cols[col][i] && !boxes[boxKey][i]) {
      rows[row][i] = 1;
      cols[col][i] = 1;
      boxes[boxKey][i] = 1;
      board[row][col] = i.toString();

      if (dfsFill(board, nRow, nCol)) return true;

      // Recover
      board[row][col] = ".";
      boxes[boxKey][i] = 0;
      cols[col][i] = 0;
      rows[row][i] = 0;
    }
  }

  return false;
}
