/*
5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
*/
#include <string>
#include <vector>

using namespace std;


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
class Solution
{
public:
  string longestPalindrome(string s)
  {
    if (s.size() < 2)
      return s;
    // dp[i][j] means string[i to j] is palindromic or not
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
    string res;

    //  dp[start + 1][end-1]) 是start， end的左下方cell, 因此要从下向上扫描
    for (int start = s.length() - 1; start >= 0; start--)
    {
      for (int end = start ; end< s.length(); end++)
      {
        dp[start][end] = s[start] == s[end] && (end -start < 3 || dp[start + 1][end-1]);
        if (dp[start][end] && end-start+1 >res.size())
        {
            res = s.substr(start, end-start+1);
        }
      }
    }
    return res;
  }
};


/*
https://zxi.mytechroad.com/blog/greedy/leetcode-5-longest-palindromic-substring/

https://www.youtube.com/watch?v=y2BD4MJqV20&ab_channel=NickWhite

Solution: Greedy   Faster than DP

Try all possible i and find the longest palindromic string whose center is i (odd case) and i / i + 1 (even case).

Time complexity: O(n^2)

Space complexity: O(1)
*/
class Solution
{
public:
  string longestPalindrome(string s)
  {
    int best_len = 0;
    int start = 0;
    for (int i = 0; i < s.length(); ++i)
    {
      int l1 = getLen(s, i, i);
      int l2 = getLen(s, i, i + 1);
      int l = max(l1, l2);
      if (l > best_len)
      {
        best_len = l;
        start = i - (l - 1) / 2;   // left = middle - (len-1) /2  len can be even or odd
      }
    }
    return s.substr(start, best_len);
  }

private:
  // find length of palindrom string, expand from the middle of the string
  int getLen(const string &s, int l, int r)
  {
    if (s[l] != s[r])
      return 1;
    while (l >= 0 && r <= s.length() - 1 && s[l] == s[r])
    {
      --l;
      ++r;
    };
    return r - l - 1;
  }
};
