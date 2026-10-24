/*
1884. Egg Drop With 2 Eggs and N Floors

https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
*/

function twoEggDrop(n: number): number {
  const dp: number[][] = Array.from({ length: 2 }, () =>
    new Array(n + 1).fill(0)
  );

  for (let j = 1; j <= n; j++) {
    dp[0][j] = j;
    dp[1][j] = 1;
  }

  for (let j = 2; j <= n; j++) {
    let min = Number.MAX_VALUE;
    for (let k = 1; k < j; k++) {
      min = Math.min(min, 1 + Math.max(dp[0][k - 1], dp[1][j - k]));
    }
    dp[1][j] = min;
  }

  return dp[1][n];
}
