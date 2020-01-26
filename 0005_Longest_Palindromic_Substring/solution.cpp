/*
5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
*/
#include <string>
#include <vector>

using namespace std;
/*
  DP
*/
class Solution
{
public:
  string longestPalindrome(string s)
  {
    if (s.empty())
      return "";
    // dp[i][j] means string[i to j] is palindromic or not
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
    string res;
    int maxLen = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
      for (int j = i; j < s.length(); j++)
      {
        if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
        {
          dp[i][j] = true; // single char is palin
          if (maxLen < j - i + 1)
          {
            maxLen = j - i + 1;
            res = s.substr(i, maxLen);
          }
        }
      }
    }
    return res;
  }
};

/*
https://zxi.mytechroad.com/blog/greedy/leetcode-5-longest-palindromic-substring/
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
        start = i - (l - 1) / 2;
      }
    }
    return s.substr(start, best_len);
  }

private:
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
