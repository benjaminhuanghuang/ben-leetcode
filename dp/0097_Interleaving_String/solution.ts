/*
97. Interleaving String

https://leetcode.com/problems/interleaving-string/
*/

function isInterleave(s1: string, s2: string, s3: string): boolean {
  const l1 = s1.length;
  const l2 = s2.length;
  const l3 = s3.length;

  if (l1 + l2 !== l3) {
    return false;
  }

  // Initialize dp array
  // dp[i][j]: whehter s3[0:i+j] is a interleva of s1[0:i] and s2[0:j]
  const dp: boolean[][] = Array.from({ length: l1 + 1 }, () =>
    Array(l2 + 1).fill(false)
  );
  dp[0][0] = true;

  // Fill dp array
  for (let i = 0; i <= l1; ++i) {
    for (let j = 0; j <= l2; ++j) {
      if (i > 0) {
        dp[i][j] ||= dp[i - 1][j] && s1[i - 1] === s3[i + j - 1];
      }
      if (j > 0) {
        dp[i][j] ||= dp[i][j - 1] && s2[j - 1] === s3[i + j - 1];
      }
    }
  }

  return dp[l1][l2];
}
