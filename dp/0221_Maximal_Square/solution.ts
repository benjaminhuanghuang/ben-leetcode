/*
221. Maximal Square

https://leetcode.com/problems/maximal-square/
*/

function maximalSquare(matrix: string[][]): number {
  if (matrix.length === 0 || matrix[0].length === 0) {
    return 0;
  }

  const m = matrix.length;
  const n = matrix[0].length;

  // Create a 2D array to store sizes of largest square ending at each cell
  const sizes: number[][] = Array.from({ length: m }, () => Array(n).fill(0));

  let maxSquareSize = 0;

  for (let i = 0; i < m; ++i) {
    for (let j = 0; j < n; ++j) {
      sizes[i][j] = parseInt(matrix[i][j]);

      if (sizes[i][j] === 0) {
        continue;
      }

      if (i === 0 || j === 0) {
        // For cells in the first row or first column, sizes[i][j] remains the same
        // as it's just the value of matrix[i][j]
      } else {
        // Calculate the size of the square ending at matrix[i][j]
        sizes[i][j] =
          Math.min(sizes[i - 1][j - 1], sizes[i - 1][j], sizes[i][j - 1]) + 1;
      }

      // Update the maximum square size found so far
      maxSquareSize = Math.max(maxSquareSize, sizes[i][j]);
    }
  }

  // Return the area of the largest square found
  return maxSquareSize * maxSquareSize;
}
