/*
1130. Minimum Cost Tree From Leaf Values

Level: Medium

https://leetcode.com/problems/minimum-cost-tree-from-leaf-values
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
  https://zxi.mytechroad.com/blog/dynamic-programming/1130-minimum-cost-tree-from-leaf-values/
  
  Solution: DP

    dp[i][j] := answer of build a tree from a[i] ~ a[j]
    dp[i][j] = min{dp[i][k] + dp[k+1][j] + max(a[i~k]) * max(a[k+1~j])} i <= k < j

    Time complexity: O(n^3)
    Space complexity: O(n^2)
*/

class Solution
{
public:
  int mctFromLeafValues(vector<int> &arr)
  {
    const int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
      m[i][i] = arr[i];
      for (int j = i + 1; j < n; ++j)
        m[i][j] = max(m[i][j - 1], arr[j]);
    }
    for (int l = 2; l <= n; ++l)
      for (int i = 0; i + l <= n; ++i)
      {
        int j = i + l - 1;
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + m[i][k] * m[k + 1][j]);
      }
    return dp[0][n - 1];
  }
};