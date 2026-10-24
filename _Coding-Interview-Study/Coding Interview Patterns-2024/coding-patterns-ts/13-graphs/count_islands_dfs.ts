/*
The time complexity of count_islands is O(rows x cols), because each cell of the matrix is visited
at most twice: once when searching for land cells in the count_islands function, and up to one
more time during DFS.

Space complexity: The space complexity is O(rows x cols) mostly due to the recursive call stack during
DFS, which can grow up to rows x cols in size.
*/
import { isWithinBounds, dirs } from "./graph";

function countIslands(matrix: number[][]): number {
  if (!matrix || matrix.length === 0) {
    return 0;
  }

  let count = 0;

  for (let r = 0; r < matrix.length; r++) {
    for (let c = 0; c < matrix[0].length; c++) {
      // If a land cell is found, perform DFS to explore the full
      // island, and include this island in our count.
      if (matrix[r][c] === 1) {
        dfs(r, c, matrix);
        count += 1;
      }
    }
  }

  return count;
}

// DFS to explore all connected land cells adjacent to the cell at (r, c).
function dfs(r: number, c: number, matrix: number[][]): void {
  // Mark the current land cell as visited.
  matrix[r][c] = -1;

  // Recursively call DFS on each neighboring land cell to continue
  // exploring this island.
  for (const d of dirs) {
    const nextR = r + d[0];
    const nextC = c + d[1];

    if (isWithinBounds(nextR, nextC, matrix) && matrix[nextR][nextC] === 1) {
      dfs(nextR, nextC, matrix);
    }
  }
}
