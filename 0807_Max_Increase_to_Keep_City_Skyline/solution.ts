/*
每个格子最多能增到 min(该行最大值, 该列最大值)，才不改变天际线
先求每行、每列的最大值，再对每个格子累加 min(rowMax, colMax) - grid[i][j]
*/
function maxIncreaseKeepingSkyline(grid: number[][]): number {
  const n = grid.length;
  const rowMax = grid.map((row) => Math.max(...row));
  const colMax = new Array(n).fill(0);

  for (let j = 0; j < n; j++) {
    for (let i = 0; i < n; i++) {
      colMax[j] = Math.max(colMax[j], grid[i][j]);
    }
  }

  let result = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      result += Math.min(rowMax[i], colMax[j]) - grid[i][j];
    }
  }

  return result;
}

export {};
