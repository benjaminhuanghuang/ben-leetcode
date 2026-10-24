/*
1277. Count Square Submatrices with All Ones

Level: Medium

https://leetcode.com/problems/count-square-submatrices-with-all-ones
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
*/

class Solution
{
public:
  int countSquares(vector<vector<int>> &matrix)
  {
    const int n = matrix.size();
    const int m = matrix[0].size();
    // dp[i][j] := edge of largest square with right bottom corner at (i, j)
    vector<vector<int>> dp(n, vector<int>(m));
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
      {
        dp[i][j] = matrix[i][j];
        if (i && j && dp[i][j])
          dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
        ans += dp[i][j];
      }
    return ans;
  }
};