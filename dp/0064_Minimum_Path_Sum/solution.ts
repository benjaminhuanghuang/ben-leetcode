/*
64. Minimum Path Sum

https://leetcode.com/problems/minimum-path-sum/
*/

function minPathSum(grid: number[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;
  const dp: number[][] = Array.from({ length: rows }, () =>
    Array(cols).fill(0)
  );

  dp[0][0] = grid[0][0];

  // Set first column
  for (let row = 1; row < rows; row++) {
    dp[row][0] = dp[row - 1][0] + grid[row][0];
  }

  // Set first row
  for (let col = 1; col < cols; col++) {
    dp[0][col] = dp[0][col - 1] + grid[0][col];
  }

  // Fill in the rest of the dp array
  for (let row = 1; row < rows; row++) {
    for (let col = 1; col < cols; col++) {
      dp[row][col] = Math.min(
        dp[row - 1][col] + grid[row][col],
        dp[row][col - 1] + grid[row][col]
      );
    }
  }

  return dp[rows - 1][cols - 1];
}
