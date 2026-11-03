/*
  Every path from (0,0) to (m-1,n-1) crosses each anti-diagonal i+j exactly once.
  If any middle diagonal has 0 cells that are both reachable from the start and
  reachable to the end, the grid is already disconnected. If a middle diagonal
  has exactly 1 such cell, that cell is a cut vertex on every path, so flipping
  it disconnects the grid. Otherwise every diagonal has >= 2 such cells, so no
  single flip can disconnect all paths.
*/
function isPossibleToCutPath(grid: number[][]): boolean {
  const m = grid.length;
  const n = grid[0].length;

  if (grid[0][0] === 0 || grid[m - 1][n - 1] === 0) return true;

  const fromStart: boolean[][] = Array.from({ length: m }, () =>
    new Array(n).fill(false)
  );
  const toEnd: boolean[][] = Array.from({ length: m }, () =>
    new Array(n).fill(false)
  );

  fromStart[0][0] = true;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === 0 || (i === 0 && j === 0)) continue;
      const up = i > 0 && fromStart[i - 1][j];
      const left = j > 0 && fromStart[i][j - 1];
      fromStart[i][j] = up || left;
    }
  }

  toEnd[m - 1][n - 1] = true;
  for (let i = m - 1; i >= 0; i--) {
    for (let j = n - 1; j >= 0; j--) {
      if (grid[i][j] === 0 || (i === m - 1 && j === n - 1)) continue;
      const down = i < m - 1 && toEnd[i + 1][j];
      const right = j < n - 1 && toEnd[i][j + 1];
      toEnd[i][j] = down || right;
    }
  }

  if (!fromStart[m - 1][n - 1]) return true;

  const diagCount = new Array(m + n - 1).fill(0);
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (fromStart[i][j] && toEnd[i][j]) diagCount[i + j]++;
    }
  }

  for (let d = 1; d <= m + n - 3; d++) {
    if (diagCount[d] <= 1) return true;
  }

  return false;
}

export { isPossibleToCutPath };
