/*
583. Delete Operation for Two Strings
https://leetcode.com/problems/delete-operation-for-two-strings/
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
  实际上就是求两个字符串的相同部分，再用两个字符串的长度减去公共部分的长度，加和即为需要改变的次数。
    */
class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int common = lcs(word1, word2);
    return word2.length() + word1.length() - 2 * common;
  }

private:
  /*
    Find Longest Common Subsequence
      https://www.youtube.com/watch?v=NnD96abizww
  */
  int lcs(string &s, string &t)
  {
    if (s.length() == 0 || t.length() == 0)
      return 0;

    int len1 = s.length(), len2 = t.length();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    int maxLen = 0;

    for (int i = 0; i <= len1; i++)
    {
      for (int j = 0; j <= len2; j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (s[i - 1] == t[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

        maxLen = max(maxLen, dp[i][j]);
      }
    }

    return maxLen;
  }
};