/*
73. Set Matrix Zeroes
https://leetcode.com/problems/set-matrix-zeroes/
*/

/*
    This method involves using the first row and column to store the information of the whole matrix.
*/
function setZeroes(matrix: number[][]): void {
  const rows = matrix.length;
  const cols = matrix[0].length;

  let firstRowHasZero = false;
  let firstColHasZero = false;

  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      if (matrix[row][col] === 0) {
        if (row === 0) {
          firstRowHasZero = true;
        }
        if (col === 0) {
          firstColHasZero = true;
        }
        matrix[0][col] = 0;
        matrix[row][0] = 0;
      }
    }
  }

  for (let row = 1; row < rows; row++) {
    for (let col = 1; col < cols; col++) {
      if (matrix[0][col] === 0 || matrix[row][0] === 0) {
        matrix[row][col] = 0;
      }
    }
  }

  if (firstRowHasZero) {
    for (let col = 0; col < cols; col++) {
      matrix[0][col] = 0;
    }
  }

  if (firstColHasZero) {
    for (let row = 0; row < rows; row++) {
      matrix[row][0] = 0;
    }
  }
}
