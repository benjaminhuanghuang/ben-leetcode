/*
1727. Largest Submatrix With Rearrangements

https://leetcode.com/problems/largest-submatrix-with-rearrangements/

85. Maximal Rectangle
*/

/*
https://www.youtube.com/watch?v=eX0lXwGu3OE&t=174s (HuaHua

matrix[i][j] := height of consecutive ones of column [j] with row[i] as the base.
*/
function largestSubmatrix(matrix: number[][]): number {
  const rows: number = matrix.length;
  const cols: number = matrix[0].length;

  for (let row = 1; row < rows; ++row) {
    for (let col = 0; col < cols; ++col) {
      // If the current cell has a 1, add the value from the cell above.
      // Each cell stores the count of consecutive 1's above it + 1 (itself, if it's 1).
      if (matrix[row][col]) {
        matrix[row][col] += matrix[row - 1][col];
      }
    }
  }

  let largestArea: number = 0;
  for (const row of matrix) {
    row.sort((a, b) => b - a); // Sort the row in descending order.
    for (let col = 0; col < cols; ++col) {
      largestArea = Math.max(largestArea, (col + 1) * row[col]);
    }
  }
  return largestArea;
}
