/*
48. Rotate Image

https://leetcode.com/problems/rotate-image/

rotate the image by 90 degrees (clockwise).
*/

// Rotate the matrix layer by layer
function rotate(matrix: number[][]): void {
  const n = matrix.length;
  const layers = n / 2;

  for (let layer = 0; layer < layers; layer++) {
    let first = layer; // index of the first element in the layer
    let last = n - 1 - layer;
    for (let i = first; i < last; i++) {
      let offset = i - first;
      const temp = matrix[first][i]; // back the up layer

      // left to up
      matrix[first][i] = matrix[last - offset][first];
      // bottom to left
      matrix[last - offset][first] = matrix[last][last - offset];
      // right to bottom
      matrix[last][last - offset] = matrix[i][last];
      // up to right
      matrix[i][last] = temp;
    }
  }
}
