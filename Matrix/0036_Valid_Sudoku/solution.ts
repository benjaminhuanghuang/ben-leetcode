/*
36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/
*/

/*
    using 3 sets to store the numbers in each row, column, and box.
*/
function isValidSudoku(board: string[][]): boolean {
  const rows = Array.from({ length: 9 }, () => new Set<string>());
  const cols = Array.from({ length: 9 }, () => new Set<string>());
  const boxes = Array.from({ length: 9 }, () => new Set<string>());

  for (let row = 0; row < 9; row++) {
    for (let col = 0; col < 9; col++) {
      const num = board[row][col];
      const boxIndex = Math.floor(row / 3) * 3 + Math.floor(col / 3);

      if (num === ".") {
        continue;
      }

      if (
        rows[row].has(num) ||
        cols[col].has(num) ||
        boxes[boxIndex].has(num)
      ) {
        return false;
      }

      rows[row].add(num);
      cols[col].add(num);
      boxes[boxIndex].add(num);
    }
  }

  return true;
}
