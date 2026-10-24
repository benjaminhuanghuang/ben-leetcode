/*

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix.
Space Complexity: O(1) - we are using only a fixed amount of extra space. The res array is not included in the space complexity.
*/
function spiralMatrix(matrix: number[][]): number[] {
  if (!matrix || matrix.length === 0) {
    return [];
  }

  const result: number[] = [];

  // Initialize the matrix boundaries.
  let top = 0;
  let bottom = matrix.length - 1;
  let left = 0;
  let right = matrix[0].length - 1;

  // Traverse the matrix in spiral order.
  while (top <= bottom && left <= right) {
    // Move from left to right along the top boundary.
    for (let i = left; i <= right; i++) {
      result.push(matrix[top][i]);
    }
    top += 1;

    // Move from top to bottom along the right boundary.
    for (let i = top; i <= bottom; i++) {
      result.push(matrix[i][right]);
    }
    right -= 1;

    // Check that the bottom boundary hasn't passed the top boundary
    // before moving from right to left along the bottom boundary.
    if (top <= bottom) {
      for (let i = right; i >= left; i--) {
        result.push(matrix[bottom][i]);
      }
      bottom -= 1;
    }

    // Check that the left boundary hasn't passed the right boundary
    // before moving from bottom to top along the left boundary.
    if (left <= right) {
      for (let i = bottom; i >= top; i--) {
        result.push(matrix[i][left]);
      }
      left += 1;
    }
  }

  return result;
}
