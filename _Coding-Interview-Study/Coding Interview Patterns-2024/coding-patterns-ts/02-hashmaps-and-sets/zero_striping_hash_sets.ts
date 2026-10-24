/*
    Time Complexity: O(M * N) where M is the number of rows and N is the number of columns in the matrix.
    Space Complexity: O(M + N) for storing the row and column indices in hash sets.
*/
export function zeroStripingHashSets(matrix: number[][]): void {
  if (!matrix || !matrix[0]) return;

  const rows = matrix.length,
    cols = matrix[0].length;

  const zeroRows = new Set<number>(),
    zeroCols = new Set<number>();

  // Pass 1: Traverse through the matrix to identify the rows and
  // columns containing zeros and store their indexes in the
  // appropriate hash sets.
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (matrix[r][c] === 0) {
        zeroRows.add(r);
        zeroCols.add(c);
      }
    }
  }
  // Pass 2: Set any cell in the matrix to zero if its row index is
  // in 'zeroRows' or its column index is in 'zeroCols'.
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (zeroRows.has(r) || zeroCols.has(c)) {
        matrix[r][c] = 0;
      }
    }
  }
}
