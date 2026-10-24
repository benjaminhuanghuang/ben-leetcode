/*
62. Unique Paths

https://leetcode.com/problems/unique-paths/
*/

/*
http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-62-unique-paths/
DP

the recursion pseudocode:
  paths(m, n):
    if(m<0 or n<0) return 0;
    if m ==1 and n == 1
      return 1
    return paths(m-1, n) + paths(m, n -1)

*/
function uniquePaths(m: number, n: number): number {
  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array(m + 1).fill(0)
  );
  dp[1][1] = 1;

  for (let row = 1; row <= n; ++row) {
    for (let col = 1; col <= m; ++col) {
      if (row === 1 || col === 1) {
        dp[row][col] = 1;
      } else {
        dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
      }
    }
  }

  return dp[n][m];
}
