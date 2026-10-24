import { dirs, isWithinBounds } from "./graph";

function longestIncreasingPath(matrix: number[][]): number {
  if (!matrix || matrix.length === 0) {
    return 0;
  }

  let res = 0;
  const rows = matrix.length;
  const cols = matrix[0].length;
  const memo: number[][] = Array.from({ length: rows }, () =>
    new Array(cols).fill(0)
  );

  // Find the longest increasing path starting at each cell. The
  // maximum of these is equal to the overall longest increasing
  // path.
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      res = Math.max(res, dfs(r, c, matrix, memo));
    }
  }

  return res;
}

function dfs(
  r: number,
  c: number,
  matrix: number[][],
  memo: number[][]
): number {
  if (memo[r][c] !== 0) {
    return memo[r][c];
  }

  let maxPath = 1;

  // The longest path starting at the current cell is equal to the
  // longest path of its larger neighboring cells, plus 1.
  for (const d of dirs) {
    const nextR = r + d[0];
    const nextC = c + d[1];

    if (
      isWithinBounds(nextR, nextC, matrix) &&
      matrix[nextR][nextC] > matrix[r][c]
    ) {
      maxPath = Math.max(maxPath, 1 + dfs(nextR, nextC, matrix, memo));
    }
  }

  memo[r][c] = maxPath;
  return maxPath;
}

/*
Time complexity: O(m x n) 
where m denotes the number of rows, and n denotes the number of columns. 

This is because each cell of the matrix is visited at most twice: once in the longest_increasing_path function, 
and during DFS where each cell is visited at most once due to memoization.

Space complexity: The space complexity is O(m x n) primarily due to the recursive call stack during
DFS, and the memoization table, both of which can grow to m x n in size.
*/
