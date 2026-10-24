/*
200. Number of Islands

https://leetcode.com/problems/number-of-islands/
*/

function numIslands(grid: string[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;
  let islands = 0;

  function dfs(row: number, col: number): void {
    if (
      row < 0 ||
      row >= rows ||
      col < 0 ||
      col >= cols ||
      grid[row][col] === "0"
    ) {
      return;
    }

    grid[row][col] = "0"; // mark as visited

    // Call the dfs function to explore all connected land cells (up, down, left, right).
    dfs(row - 1, col);
    dfs(row + 1, col);
    dfs(row, col - 1);
    dfs(row, col + 1);
  }

  for (let row = 0; row < rows; row++) {
    for (let col = 0; col < cols; col++) {
      if (grid[row][col] === "1") {
        islands++; // Found a new island, count++
        dfs(row, col); // mark all the connected land as visited
      }
    }
  }

  return islands;
}
