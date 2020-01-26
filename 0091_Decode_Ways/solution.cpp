/*
91. Decode Ways

https://leetcode.com/problems/decode-ways/

一个加密的数字字符串，一共有多少种不同的解密方式。
*/

#include <string>
#include <vector>

using namespace std;
/*
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-91-decode-ways/
*/
class Solution
{
public:
  int numDecodings(string s)
  {
  }
};

/*
Lai Offer
https://www.youtube.com/watch?v=ZLwwc3-vVP4&t=74s
 */

class Solution
{
public:
  int numDecodings(string s)
  {
    if (s.empty() || s[0] == '0')
      return 0;

    if (s.length() == 1)
      return 1;

    vector<int> dp(s.length());
    dp[0] = 1;

    if (stoi(s.substr(0, 2)) > 26)
    {
      if (s[1] != '0')
      {
        dp[1] = 1;
      }
      else
      {
        dp[1] = 0;
      }
    }
    else
    {
      if (s[1] != '0')
      {
        dp[1] = 2;
      }
      else
      {
        dp[1] = 1;
      }
    }

    for (int i = 2; i < s.length(); i++)
    {
      if (s[i] != '0')
      {
        dp[i] += dp[i - 1];
      }

      int val = stoi(s.substr(i - 1, 2));
      if (val <= 26 && val >= 10)
      {
        dp[i] += dp[i - 2];
      }
    }

    return dp[s.length() - 1];
  }
};