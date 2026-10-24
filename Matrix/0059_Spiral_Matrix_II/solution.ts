/*
59. Spiral Matrix II

https://leetcode.com/problems/spiral-matrix-ii/
*/

function generateMatrix(n: number): number[][] {
  const matrix: number[][] = new Array(n)
    .fill(0)
    .map(() => new Array(n).fill(0));
  let left = 0;
  let right = n - 1;
  let top = 0;
  let bottom = n - 1;

  let num = 1;

  while (left <= right && top <= bottom) {
    // top
    for (let i = left; i <= right; i++) {
      matrix[top][i] = num++;
    }
    top++;

    // right
    for (let i = top; i <= bottom; i++) {
      matrix[i][right] = num++;
    }
    right--;

    // bottom
    for (let i = right; i >= left; i--) {
      matrix[bottom][i] = num++;
    }
    bottom--;

    // left
    for (let i = bottom; i >= top; i--) {
      matrix[i][left] = num++;
    }
    left++;
  }

  return matrix;
}
