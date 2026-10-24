/*
74. Search a 2D Matrix

https://leetcode.com/problems/search-a-2d-matrix/
*/

/*
use huahua's template
*/
function searchMatrix(matrix: number[][], target: number): boolean {
  const rows = matrix.length;
  if (rows === 0) return false;
  const cols = matrix[0].length;

  let low = 0;
  let high = rows * cols;

  while (low < high) {
    const mid = Math.floor((high - low) / 2) + low;
    const row = Math.floor(mid / cols);
    const col = mid % cols;

    if (matrix[row][col] === target) {
      return true;
    } else if (matrix[row][col] > target) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return false;
}
