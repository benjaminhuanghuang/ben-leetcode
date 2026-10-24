/*
10. Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/
*/

/*
DP
dp[i][j]表示 s[0..i-1] 是否匹配p[0..j-1].    i, j are length

if p[j - 1] != '*'

     dp[i][j] = dp[i-1][j-1]&& (p[j-1]=='.'||s[i-1]==p[j-1])

if p[j - 1] == '*', 设 p[j - 2] 为 x

      1) "x*" 重复0次：f[i][j] = dp[i][j - 2]

      2)"x*" 重复1次以上：f[i][j] = dp[i-1][j] && (p[j-2]=='.'||s[i-1]==p[j-2])


*/
function isMatch(s: string, p: string): boolean {
  const m = s.length,
    n = p.length;
  const dp: boolean[][] = Array.from({ length: m + 1 }, () =>
    Array(n + 1).fill(false)
  );
  dp[0][0] = true; // empty string matches

  // dp[x][0] are false, empty p cannot match any non-empty s
  for (let i = 1; i <= m; ++i) {
    dp[i][0] = false;
  }

  // go through the characters in p
  // s "" matches p "x*"
  for (let i = 1; i <= n; ++i) {
    dp[0][i] = p[i - 1] === "*" && dp[0][i - 2];
  }

  for (let i = 1; i <= m; ++i) {
    for (let j = 1; j <= n; ++j) {
      if (p[j - 1] !== "*") {
        dp[i][j] =
          dp[i - 1][j - 1] && (p[j - 1] === "." || s[i - 1] === p[j - 1]);
      } else {
        dp[i][j] =
          dp[i][j - 2] ||
          (dp[i - 1][j] && (p[j - 2] === "." || s[i - 1] === p[j - 2]));
      }
    }
  }
  return dp[m][n];
}
