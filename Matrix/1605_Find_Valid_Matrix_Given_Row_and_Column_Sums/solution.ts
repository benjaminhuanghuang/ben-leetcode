/*
1605. Find Valid Matrix Given Row and Column Sums

https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

*/

/*
sum(rowSum) == sum(colSum)
*/
function restoreMatrix(rowSum: number[], colSum: number[]): number[][] {
  const rows = rowSum.length;
  const cols = colSum.length;
  const matrix = Array.from({ length: rows }, () => Array(cols).fill(0));

  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      // Greedy, take the minimum of rowSum and colSum
      const val = Math.min(rowSum[row], colSum[col]);
      matrix[row][col] = val;
      rowSum[row] -= val;
      colSum[col] -= val;
    }
  }

  return matrix;
}
