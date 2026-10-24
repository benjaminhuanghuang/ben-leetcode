/*
3195. Find the Minimum Area to Cover All Ones I

https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
*/

function minimumArea(grid: number[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;

  let [x1, y1] = [rows, cols]; // end points of the rectangle
  let [x2, y2] = [0, 0]; // start points of the rectangle
  for (let row = 0; row < rows; ++row) {
    for (let col = 0; col < cols; ++col) {
      if (grid[row][col] === 1) {
        // shrink the bottom-right corner
        x1 = Math.min(x1, row);
        y1 = Math.min(y1, col);
        // expand the top-left corner
        x2 = Math.max(x2, row);
        y2 = Math.max(y2, col);
      }
    }
  }
  return (x2 - x1 + 1) * (y2 - y1 + 1);
}
