/*

Rotting Oranges


Talk-through: Multi-source BFS — seed the queue with every rotten orange at
once instead of one at a time, so the BFS naturally expands in minute-by-
minute waves. Track remaining fresh oranges; each successful infection
decrements it. If fresh oranges remain after the BFS drains, some were
unreachable.

Time big O of rows * cols, space big O of rows * cols.
*/
function orangesRotting(grid: number[][]): number {
  const rows = grid.length;
  const cols = grid[0].length;
  const queue: [number, number][] = [];
  let fresh = 0;

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 2) queue.push([r, c]);
      if (grid[r][c] === 1) fresh++;
    }
  }

  const directions = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
  ];
  let minutes = 0;

  while (queue.length > 0 && fresh > 0) {
    const size = queue.length;

    for (let i = 0; i < size; i++) {
      const [r, c] = queue.shift()!;

      for (const [dr, dc] of directions) {
        const nr = r + dr;
        const nc = c + dc;

        if (
          nr >= 0 &&
          nr < rows &&
          nc >= 0 &&
          nc < cols &&
          grid[nr][nc] === 1
        ) {
          grid[nr][nc] = 2;
          fresh--;
          queue.push([nr, nc]);
        }
      }
    }

    minutes++;
  }

  return fresh === 0 ? minutes : -1;
}
