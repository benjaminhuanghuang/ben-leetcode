/*
516. Longest Palindromic Subsequence

https://leetcode.com/problems/longest-palindromic-subsequence/
*/

/*
    https://www.youtube.com/watch?v=OZX1nqaQ_9M (HuaHua)

    Solution 1: DP
        dp[i][j]:= solution of s[i..j] 
    
        for len = 1 to n:
            for i = 0 ton - len:
                j= i + 1 - 1
                if s[1] == s[j]:
                dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                dp[i][j] = max(dp[i + 1][j], dp [i][j - 1])
    Ans: dp [0][n-1]    

    Base case 1:
        s[i] = s[j] => dp[i][j] = dp[i + 1][j - 1] + 2

    Base case 2:
        s[i] != s[j] => dp[i][j] = max(dp[i + 1][j], dp [i][j - 1])   

    Time complexity: 0(n^2)
    Space complexity: 0(n^2)
*/
function longestPalindromeSubseq(s: string): number {
  const n = s.length;
  const dp: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

  for (let l = 1; l <= n; ++l) {
    for (let i = 0; i <= n - l; ++i) {
      const j = i + l - 1;
      if (i === j) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
        if (s[i] === s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
      }
    }
  }

  return dp[0][n - 1];
}

/*
https://algo.monster/liteproblems/516
*/
function longestPalindromeSubseq_2(s: string): number {
  const length = s.length;

  // Create a 2D DP table where dp[i][j] represents the length of
  // the longest palindromic subsequence in substring s[i...j]
  const dp: number[][] = Array.from({ length: length }, () =>
    Array(length).fill(0)
  );

  // Base case: every single character is a palindrome of length 1
  for (let i = 0; i < length; i++) {
    dp[i][i] = 1;
  }

  // Fill the DP table by iterating through all possible substrings
  // Start from the second last row and move upward
  for (let startIndex = length - 2; startIndex >= 0; startIndex--) {
    // For each starting position, check all ending positions after it
    for (let endIndex = startIndex + 1; endIndex < length; endIndex++) {
      if (s[startIndex] === s[endIndex]) {
        // If characters match, add 2 to the result of the inner substring
        dp[startIndex][endIndex] = dp[startIndex + 1][endIndex - 1] + 2;
      } else {
        // If characters don't match, take the maximum of either
        // excluding the left character or excluding the right character
        dp[startIndex][endIndex] = Math.max(
          dp[startIndex + 1][endIndex],
          dp[startIndex][endIndex - 1]
        );
      }
    }
  }

  // The result for the entire string is stored at dp[0][length - 1]
  return dp[0][length - 1];
}
