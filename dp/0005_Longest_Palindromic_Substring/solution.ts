/*
5. Longest Palindromic Substring

https://leetcode.com/problems/longest-palindromic-substring/
*/
/*
  516 - Longest Palindromic Subsequence【FLAG高频精选面试题讲解】
  https://www.youtube.com/watch?reload=9&v=v8irqkTcJ6s

  Brute force solution: (N^3)
      generate all substring (N^2)
      check if a string is a palindrome (N)  


  DP
  DP[i][j]  = s[i..j]
  
  base case:
    DP[i][i-1] =0 size = 0
    DP[i][i] =1 size = 1 

  if(s[i] == s[j])
    dp[i][j] = dp[i+1][j-1] + 2
  else
    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
*/
function longestPalindrome(s: string): string {
  if (s.length < 2) {
    return s;
  }

  const n = s.length;
  const dp: boolean[][] = Array.from({ length: n }, () => Array(n).fill(false));
  let res = "";

  for (let start = n - 1; start >= 0; start--) {
    for (let end = start; end < n; end++) {
      dp[start][end] =
        s[start] === s[end] && (end - start < 3 || dp[start + 1][end - 1]);

      if (dp[start][end] && end - start + 1 > res.length) {
        res = s.substring(start, end + 1);
      }
    }
  }

  return res;
}

/*
https://zxi.mytechroad.com/blog/greedy/leetcode-5-longest-palindromic-substring/

https://www.youtube.com/watch?v=y2BD4MJqV20&ab_channel=NickWhite

Solution: Greedy   Faster than DP

Try all possible i and find the longest palindromic string whose center is i (odd case) and i / i + 1 (even case).

Time complexity: O(n^2)

Space complexity: O(1)
*/

/*
    Time complexity: O(n^2)
*/
function longestPalindrome_fast(s: string): string {
  let maxString = "";
  let maxLength: number = 0;
  for (let i = 0; i < s.length; i++) {
    let oddPal = getPalindrome(s, i, i);
    let evenPal = getPalindrome(s, i, i + 1);
    if (oddPal.length > maxLength) {
      maxString = oddPal;
      maxLength = oddPal.length;
    }
    if (evenPal.length > maxLength) {
      maxString = evenPal;
      maxLength = evenPal.length;
    }
  }
  return maxString;
}

const getPalindrome = (s: string, left: number, right: number): string => {
  while (left >= 0 && right < s.length && s[left] === s[right]) {
    left--;
    right++;
  }
  return s.substring(left + 1, right);
};
