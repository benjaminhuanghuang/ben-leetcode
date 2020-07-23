/*
474. Ones and Zeroes

Level: Medium

https://leetcode.com/problems/ones-and-zeroes
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
  从数组中取出最多的字符串，这些字符串中1和0的出现次数之和不超过m，n.

  Solution: 
*/

class Solution
{
public:
  int findMaxForm(vector<string> &strs, int m, int n)
  {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
    int ans = dp[0][0] = 0;
    for (string s : strs)
    {
      int zero = 0, one = 0;
      for (int i = 0; i < s.size(); i++)
      {
        if (s[i] == '0')
        {
          zero++;
        }
        else
        {
          one++;
        }
      }
      for (int i = m; i > zero - 1; i--)
      {
        for (int j = n; j > one - 1; j--)
        {
          dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
        }
      }
    }
    return dp[m][n];
  }
};