/*
639. Decode Ways II

Level: Hard

https://leetcode.com/problems/decode-ways-ii
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-639-decode-ways-ii/
*/

class Solution
{
public:
  int numDecodings(string s)
  {
    if (s.empty())
      return 0;
    //           dp[-1]  dp[0]
    long dp[2] = {1, ways(s[0])};
    for (int i = 1; i < s.length(); ++i)
    {
      long dp_i = ways(s[i]) * dp[1] + ways(s[i - 1], s[i]) * dp[0];
      dp_i %= kMod;
      dp[0] = dp[1];
      dp[1] = dp_i;
    }
    return dp[1];
  }

private:
  static constexpr int kMod = 1000000007;

  int ways(char c)
  {
    if (c == '0')
      return 0;
    if (c == '*')
      return 9;
    return 1;
  }

  int ways(char c1, char c2)
  {
    if (c1 == '*' && c2 == '*')
      return 15;
    if (c1 == '*')
    {
      return (c2 >= '0' && c2 <= '6') ? 2 : 1;
    }
    else if (c2 == '*')
    {
      switch (c1)
      {
      case '1':
        return 9;
      case '2':
        return 6;
      default:
        return 0;
      }
    }
    else
    {
      int prefix = (c1 - '0') * 10 + (c2 - '0');
      return prefix >= 10 && prefix <= 26;
    }
  }
};