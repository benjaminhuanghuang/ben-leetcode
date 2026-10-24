/*
733. Flood Fill

https://leetcode.com/problems/flood-fill/


- 200. Number of Islands
- 547. Friend Circles
- 695. Max Area of Island
*/

/*
https://www.youtube.com/watch?v=ln_mc5LtL5M (Huahua)
Time Complexity: O(M * N)

*/
function floodFill(
  image: number[][],
  sr: number,
  sc: number,
  color: number
): number[][] {
  if (image[sr][sc] === color) return image;
  const rows = image.length;
  const cols = image[0].length;

  function dfs(
    image: number[][],
    col: number,
    row: number,
    cols: number,
    rows: number,
    orgColor: number,
    newColor: number
  ): void {
    if (col < 0 || col >= cols || row < 0 || row >= rows) return;
    if (image[row][col] !== orgColor) return;

    image[row][col] = newColor;
    dfs(image, col + 1, row, cols, rows, orgColor, newColor);
    dfs(image, col - 1, row, cols, rows, orgColor, newColor);
    dfs(image, col, row + 1, cols, rows, orgColor, newColor);
    dfs(image, col, row - 1, cols, rows, orgColor, newColor);
  }

  dfs(image, sc, sr, cols, rows, image[sr][sc], color);
  return image;
}
