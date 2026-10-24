/*
54. Spiral Matrix

https://leetcode.com/problems/spiral-matrix/
*/

function spiralOrder(matrix: number[][]): number[] {
  let left = 0;
  let right = matrix[0].length - 1;
  let top = 0;
  let bottom = matrix.length - 1;

  const res: number[] = [];
  let direct = 0;

  while (left <= right && top <= bottom) {
    // top
    if (direct === 0) {
      for (let i = left; i <= right; i++) {
        res.push(matrix[top][i]);
      }
      top++;
    }
    // right
    else if (direct === 1) {
      for (let i = top; i <= bottom; i++) {
        res.push(matrix[i][right]);
      }
      right--;
    }
    // bottom
    else if (direct === 2) {
      for (let i = right; i >= left; i--) {
        res.push(matrix[bottom][i]);
      }
      bottom--;
    }
    // left
    else if (direct === 3) {
      for (let i = bottom; i >= top; i--) {
        res.push(matrix[i][left]);
      }
      left++;
    }
    direct = (direct + 1) % 4; // change direction
  }

  return res;
}
