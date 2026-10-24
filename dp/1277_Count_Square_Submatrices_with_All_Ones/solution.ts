/*
1277. Count Square Submatrices with All Ones

https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

function countSquares(matrix: number[][]): number {
  const rows = matrix.length;
  const cols = matrix[0].length; // dimensions for matrix
  let ans = 0;
  const dp: number[][] = Array.from({ length: rows }, () =>
    Array(cols).fill(0)
  );

  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      if (row === 0 || col === 0) {
        // cell is in the first row or column
        dp[row][col] = matrix[row][col];
      } else if (matrix[row][col] === 1) {
        dp[row][col] =
          Math.min(dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]) +
          1;
      }
      ans += dp[row][col];
    }
  }

  return ans;
}
