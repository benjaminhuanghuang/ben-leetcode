/*
764. Largest Plus Sign

Level: Medium

https://leetcode.com/problems/largest-plus-sign
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

  https://www.cnblogs.com/grandyang/p/8679286.html
*/

class Solution
{
public:
  int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
  {
    int res = 0;
    vector<vector<int>> dp(N, vector<int>(N, N));
    for (auto mine : mines)
      dp[mine[0]][mine[1]] = 0;
    for (int i = 0; i < N; ++i)
    {
      int l = 0, r = 0, u = 0, d = 0;
      for (int j = 0, k = N - 1; j < N; ++j, --k)
      {
        dp[i][j] = min(dp[i][j], l = (dp[i][j] ? l + 1 : 0));
        dp[j][i] = min(dp[j][i], u = (dp[j][i] ? u + 1 : 0));
        dp[i][k] = min(dp[i][k], r = (dp[i][k] ? r + 1 : 0));
        dp[k][i] = min(dp[k][i], d = (dp[k][i] ? d + 1 : 0));
      }
    }
    for (int k = 0; k < N * N; ++k)
      res = max(res, dp[k / N][k % N]);
    return res;
  }
};