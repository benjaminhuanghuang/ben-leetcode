/*
994. Rotting Oranges

https://leetcode.com/problems/rotting-oranges/

0- empty cell, 1-fresh orange, 2-rotten orange
Return the minimum number of minutes that all oranges are rotten. If this is impossible, return -1
*/

/*
Approach: BFS

*/

const dirs: [number, number][] = [
  [-1, 0],
  [1, 0],
  [0, -1],
  [0, 1],
];

function isWithinBounds(r: number, c: number, matrix: number[][]): boolean {
  return r >= 0 && r < matrix.length && c >= 0 && c < matrix[0].length;
}

function orangesRotting_use_dirs(grid: number[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;

  const q: [number, number][] = [];
  let fresh = 0;

  // count fresh oranges and push rotten oranges to the queue
  for (let row = 0; row < rows; ++row) {
    for (let col = 0; col < cols; ++col) {
      if (grid[row][col] === 1) {
        ++fresh;
      } else if (grid[row][col] === 2) {
        q.push([col, row]);
      }
    }
  }

  let minutes = 0;

  while (q.length > 0 && fresh) {
    let size = q.length;
    while (size--) {
      const [x, y] = q.shift()!;
      for (const d of dirs) {
        const dx = x + d[0];
        const dy = y + d[1];
        if (isWithinBounds(dy, dx, grid) && grid[dy][dx] === 1) {
          --fresh;
          grid[dy][dx] = 2;
          q.push([dx, dy]);
        }
      }
    }
    ++minutes;
  }
  return fresh ? -1 : minutes;
}

function orangesRotting(grid: number[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;

  const q: [number, number][] = [];
  let fresh = 0;

  // count fresh oranges and push rotten oranges to the queue
  for (let row = 0; row < rows; ++row) {
    for (let col = 0; col < cols; ++col) {
      if (grid[row][col] === 1) {
        ++fresh;
      } else if (grid[row][col] === 2) {
        q.push([col, row]);
      }
    }
  }

  const dirs = [1, 0, -1, 0, 1];
  let minutes = 0;

  while (q.length > 0 && fresh) {
    let size = q.length;
    while (size--) {
      const [x, y] = q.shift()!;
      for (let i = 0; i < 4; ++i) {
        const dx = x + dirs[i];
        const dy = y + dirs[i + 1];
        if (
          dx < 0 ||
          dx >= cols ||
          dy < 0 ||
          dy >= rows ||
          grid[dy][dx] !== 1
        ) {
          continue;
        }
        --fresh;
        grid[dy][dx] = 2;
        q.push([dx, dy]);
      }
    }
    ++minutes;
  }

  return fresh ? -1 : minutes;
}
