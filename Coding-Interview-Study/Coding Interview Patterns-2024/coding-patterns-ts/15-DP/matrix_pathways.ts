function matrixPathways(m: number, n: number): number {
  // Initialize all cells to 1 (base cases)
  const dp: number[][] = Array.from({ length: m }, () => new Array(n).fill(1));

  // Fill in the rest of the DP table
  for (let r = 1; r < m; r++) {
    for (let c = 1; c < n; c++) {
      // Paths to current cell = paths from above + paths from left
      dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
    }
  }

  return dp[m - 1][n - 1];
}

/*
Time complexity: The time complexity of matrix_pathways is O(m • n) because each cell in the
DP table is populated once.

Space complexity: The space complexity is O(m · n) due to the DP table, which contains m · n
elements.
*/
