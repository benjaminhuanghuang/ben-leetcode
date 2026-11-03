/*
A single flip can disconnect the matrix if and only if there is a bottleneck cell (an articulation point) 
that all valid paths must pass through.

2-Pass Reachability
1. dp1 checks which cells are reachable from the start (0, 0) going down/right.
2. dp2 checks which cells can reach the end (m - 1, n - 1) going backwards up/left.
3. If a cell has both dp1 and dp2 as true, it lies on at least one valid path.

*/
var isPossibleToDisconnect = function (grid) {
  const m = grid.length,
    n = grid[0].length;

  // dp1[r][c]: true if (r, c) is reachable from start (0, 0)
  const dp1 = Array.from({ length: m }, () => Array(n).fill(false));
  dp1[0][0] = true;
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (grid[r][c] === 1) {
        if (r > 0 && dp1[r - 1][c]) dp1[r][c] = true;
        if (c > 0 && dp1[r][c - 1]) dp1[r][c] = true;
      }
    }
  }

  // If start cannot even reach end, it is already disconnected
  if (!dp1[m - 1][n - 1]) return true;

  // dp2[r][c]: true if (r, c) can reach end (m - 1, n - 1)
  const dp2 = Array.from({ length: m }, () => Array(n).fill(false));
  dp2[m - 1][n - 1] = true;
  for (let r = m - 1; r >= 0; r--) {
    for (let c = n - 1; c >= 0; c--) {
      if (grid[r][c] === 1) {
        if (r + 1 < m && dp2[r + 1][c]) dp2[r][c] = true;
        if (c + 1 < n && dp2[r][c + 1]) dp2[r][c] = true;
      }
    }
  }

  // Count active cells on each diagonal step: step = r + c
  // Total steps from start to end = (m - 1) + (n - 1)
  const stepCount = new Array(m + n - 1).fill(0);

  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      // Cell is part of a valid path from (0,0) to (m-1, n-1)
      if (dp1[r][c] && dp2[r][c]) {
        stepCount[r + c]++;
      }
    }
  }

  // Check internal steps (exclude start at 0 and end at m + n - 2)
  for (let step = 1; step < m + n - 2; step++) {
    // A "bottleneck" cell: only 1 path passes through this step!
    if (stepCount[step] <= 1) {
      return true; // Flipping this single cell disconnects the path
    }
  }

  return false;
};
