/*
1329. Sort the Matrix Diagonally

https://leetcode.com/problems/sort-the-matrix-diagonally/
*/

function diagonalSort(mat: number[][]): number[][] {
  const rows = mat.length;
  const cols = mat[0].length;
  // Use an object to store elements from each diagonal
  const diagonals: { [key: number]: number[] } = {};

  // Step 1: Collect elements from each diagonal
  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      // Use i - j as the key for each diagonal
      const diagonalKey = row - col;
      if (!diagonals[diagonalKey]) {
        diagonals[diagonalKey] = [];
      }
      // Add the current element to its diagonal array
      diagonals[diagonalKey].push(mat[row][col]);
    }
  }

  // Step 2: Sort each diagonal
  for (let key in diagonals) {
    // Sort the elements in ascending order
    diagonals[key].sort((a, b) => a - b);
  }

  // Step 3: Put the sorted elements back into the matrix
  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      const diagonalKey = row - col;
      // Use shift() to get the next element from the sorted diagonal array
      mat[row][col] = diagonals[diagonalKey].shift()!;
    }
  }
  return mat;
}
