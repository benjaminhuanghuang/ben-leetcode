/*
1314. Matrix Block Sum

https://leetcode.com/problems/matrix-block-sum/
*/

/*
    K is the size of the block
*/
function matrixBlockSum(mat: number[][], k: number): number[][] {
  const rows = mat.length;
  const cols = mat[0].length;
  const temp: number[][] = Array.from({ length: rows + 1 }, () =>
    Array(cols + 1).fill(0)
  );

  // prefix sum of the matrix[i][j] = sum of the matrix[0][0] to matrix[i][j]
  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      temp[row + 1][col + 1] =
        temp[row + 1][col] +
        temp[row][col + 1] -
        temp[row][col] +
        mat[row][col];
    }
  }

  const res: number[][] = Array.from({ length: rows }, () =>
    Array(cols).fill(0)
  );

  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      const r1 = Math.max(0, row - k);
      const c1 = Math.max(0, col - k);
      const r2 = Math.min(rows, row + k + 1);
      const c2 = Math.min(cols, col + k + 1);
      res[row][col] = temp[r2][c2] - temp[r2][c1] - temp[r1][c2] + temp[r1][c1];
    }
  }

  return res;
}
