function longestPalindromeInAString(s: string): string {
  const n = s.length;
  if (n === 0) return "";

  const dp: boolean[][] = Array.from({ length: n }, () =>
    new Array(n).fill(false)
  );
  let maxLen = 1;
  let startIndex = 0;

  // Base case: single characters are palindromes
  for (let i = 0; i < n; i++) {
    dp[i][i] = true;
  }

  // Base case: substrings of length 2
  for (let i = 0; i < n - 1; i++) {
    if (s[i] === s[i + 1]) {
      dp[i][i + 1] = true;
      maxLen = 2;
      startIndex = i;
    }
  }

  // Substrings of length >= 3
  for (let substringLen = 3; substringLen <= n; substringLen++) {
    for (let i = 0; i <= n - substringLen; i++) {
      const j = i + substringLen - 1;
      if (s[i] === s[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
        maxLen = substringLen;
        startIndex = i;
      }
    }
  }

  return s.slice(startIndex, startIndex + maxLen);
}
/*
Time complexity: The time complexity of longestPalindromeInAString is O(n^2) because
each cell of the n × n DP table is populated once.

Space complexity: The space complexity is O(n^2) because we're maintaining a DP table that has n^2 elements. 
Note: the output string is not considered in the space complexity.
*/
