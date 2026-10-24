/*
1992. Find All Groups of Farmland

https://leetcode.com/problems/find-all-groups-of-farmland/

0-forest, 1-farmland
Find the coordinates of the top left and bottom right corner of each group of farmland
*/

function findFarmland(land: number[][]): number[][] {
  const farmlands: number[][] = [];
  const rows: number = land.length;
  const cols: number = land[0].length;

  for (let row = 0; row < rows; ++row) {
    for (let col = 0; col < cols; ++col) {
      // Skip the cell if it:
      // is 0, not part of farmland,
      // or if it's left edge is adjacent to an already identified farmland plot
      // or if it's top edge is adjacent to an already identified farmland plot
      if (
        land[row][col] === 0 ||
        (col > 0 && land[row][col - 1] === 1) ||
        (row > 0 && land[row - 1][col] === 1)
      ) {
        continue;
      }

      // Initialize the top-left corner of the current farmland with the coordinates (i, j)
      let topLeftX: number = row;
      let topLeftY: number = col;
      let bottomRightX: number = row;
      let bottomRightY: number = col;

      // Expand in the downward direction (increment rows)
      while (bottomRightX + 1 < rows && land[bottomRightX + 1][col] === 1) {
        bottomRightX++;
      }

      // Expand in the rightward direction (increment columns)
      while (bottomRightY + 1 < cols && land[row][bottomRightY + 1] === 1) {
        bottomRightY++;
      }

      // Store the coordinates of the current farmland as a tuple [topLeftX, topLeftY, bottomRightX, bottomRightY]
      farmlands.push([topLeftX, topLeftY, bottomRightX, bottomRightY]);

      // Mark the identified farmland in the matrix to ensure it is not processed again
      for (let x = topLeftX; x <= bottomRightX; x++) {
        for (let y = topLeftY; y <= bottomRightY; y++) {
          land[x][y] = 0;
        }
      }
    }
  }
  return farmlands;
}
