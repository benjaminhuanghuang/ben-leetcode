/*
931. Minimum Falling Path Sum

Level: Medium

https://leetcode.com/problems/minimum-falling-path-sum
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

    Time complexity: O(mn)

    Space complexity: O(mn)
*/

class Solution
{
public:
  int minFallingPathSum(vector<vector<int>> &A)
  {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n; ++i)
    {
      dp[i][0] = dp[i][m + 1] = INT_MAX;
      for (int j = 1; j <= m; ++j)
        dp[i][j] = *min_element(dp[i - 1].begin() + j - 1,
                                dp[i - 1].begin() + j + 2) +
                   A[i - 1][j - 1];
    }
    return *min_element(dp[n].begin() + 1, dp[n].end() - 1);
  }
};