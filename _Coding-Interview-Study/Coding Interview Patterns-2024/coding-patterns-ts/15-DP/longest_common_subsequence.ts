function longest_common_subsequence(s1: string, s2: string): number {
  const m = s1.length;
  const n = s2.length;

  // Initialize DP table with 0s (size: (m+1) × (n+1))
  const dp: number[][] = Array.from({ length: m + 1 }, () =>
    new Array(n + 1).fill(0)
  );

  // Populate the DP table bottom-up
  for (let i = m - 1; i >= 0; i--) {
    for (let j = n - 1; j >= 0; j--) {
      if (s1[i] === s2[j]) {
        // Characters match → 1 + diagonal value
        dp[i][j] = 1 + dp[i + 1][j + 1];
      } else {
        // Characters don't match → take max of skipping one character
        dp[i][j] = Math.max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  // The top-left cell stores the final LCS length
  return dp[0][0];
}
/*
Time complexity: The time complexity of longest_common_subsequence is O(m · n), where m and n denote the lengths of s1 and s2.
This is because each cell in the DP table is populated once.

Space complexity: The space complexity is O(m · n) since we're maintaining a 2D DP table that has (m + 1) · (n + 1) elements.
*/
