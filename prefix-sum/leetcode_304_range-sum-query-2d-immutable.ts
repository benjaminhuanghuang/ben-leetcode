/*
304. Range Sum Query 2D - Immutable

https://leetcode.com/problems/range-sum-query-2d-immutable/
*/

class NumMatrix {
  private sums: number[][];

  constructor(matrix: number[][]) {
    this.sums = [];

    if (matrix.length === 0 || matrix[0].length === 0) return;

    const rows = matrix.length;
    const cols = matrix[0].length;

    // Initialize sums_ with an extra row and column filled with 0s
    this.sums = Array.from({ length: rows + 1 }, () => Array(cols + 1).fill(0));

    for (let i = 1; i <= rows; ++i) {
      for (let j = 1; j <= cols; ++j) {
        this.sums[i][j] =
          matrix[i - 1][j - 1] +
          this.sums[i - 1][j] +
          this.sums[i][j - 1] -
          this.sums[i - 1][j - 1];
      }
    }
  }

  sumRegion(row1: number, col1: number, row2: number, col2: number): number {
    return (
      this.sums[row2 + 1][col2 + 1] -
      this.sums[row2 + 1][col1] -
      this.sums[row1][col2 + 1] +
      this.sums[row1][col1]
    );
  }
}
