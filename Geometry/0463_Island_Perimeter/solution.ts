/*
463. Island Perimeter

https://leetcode.com/problems/island-perimeter/
*/

function islandPerimeter(grid: number[][]): number {
  let perimeter = 0;
  let m = grid.length;
  let n = grid[0].length;

  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (grid[r][c] === 1) {
        perimeter += 4;
        // Check the left and top blocks
        if (r > 0 && grid[r - 1][c] === 1) perimeter -= 2;
        if (c > 0 && grid[r][c - 1] === 1) perimeter -= 2;
      }
    }
  }

  return perimeter;
}

/*
  Solution: 
  列举可以贡献边长的block
*/
