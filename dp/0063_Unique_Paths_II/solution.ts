/*
63. Unique Paths II

https://leetcode.com/problems/unique-paths-ii/
*/

function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
  if (
    obstacleGrid.length === 0 ||
    obstacleGrid[0].length === 0 ||
    obstacleGrid[0][0] === 1
  ) {
    return 0;
  }

  const rows = obstacleGrid.length;
  const cols = obstacleGrid[0].length;
  const dp: number[][] = Array.from({ length: rows + 1 }, () =>
    Array(cols + 1).fill(0)
  );

  dp[0][1] = 1; // Initialize dp[1][1] by setting dp[0][1] to 1

  for (let row = 1; row <= rows; ++row) {
    for (let col = 1; col <= cols; ++col) {
      if (obstacleGrid[row - 1][col - 1] !== 0) {
        // obstacle
        continue;
      }
      dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
    }
  }

  return dp[rows][cols];
}
