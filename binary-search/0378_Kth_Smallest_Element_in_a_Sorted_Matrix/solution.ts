/*
378. Kth Smallest Element in a Sorted Matrix

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

/*
   is similar to 240. Search a 2D Matrix II. 
   The start point of such a sorted matrix is left-bottom corner.
  */
function kthSmallest(matrix: number[][], k: number): number {
  const n = matrix.length;
  let l = matrix[0][0];
  let r = matrix[n - 1][n - 1] + 1;

  while (l < r) {
    const mid = l + ((r - l) >> 1);
    const count = counter(matrix, mid);
    if (count < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  return l;
}

function counter(matrix: number[][], target: number): number {
  const size = matrix.length;
  let row = size - 1;
  let col = 0;
  let count = 0;

  while (row >= 0 && col < size) {
    if (matrix[row][col] <= target) {
      count += row + 1; // add count in vertical
      col++;
    } else {
      row--;
    }
  }

  return count;
}
