/*
903. Valid Permutations for DI Sequence

Level: Hard

https://leetcode.com/problems/valid-permutations-for-di-sequence
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
  Solution: DP
  https://www.cnblogs.com/grandyang/p/11094525.html
*/

class Solution
{
public:
  int numPermsDISequence(string S)
  {
    int n = S.size(), M = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int j = 0; j <= n; ++j)
      dp[0][j] = 1;
    for (int i = 0; i < n; ++i)
    {
      if (S[i] == 'I')
      {
        for (int j = 0, cur = 0; j < n - i; ++j)
        {
          dp[i + 1][j] = cur = (cur + dp[i][j]) % M;
        }
      }
      else
      {
        for (int j = n - 1 - i, cur = 0; j >= 0; --j)
        {
          dp[i + 1][j] = cur = (cur + dp[i][j + 1]) % M;
        }
      }
    }
    return dp[n][0];
  }
};
