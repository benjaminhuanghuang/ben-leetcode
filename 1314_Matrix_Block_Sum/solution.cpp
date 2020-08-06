/*
1314. Matrix Block Sum

Level: Medium

https://leetcode.com/problems/matrix-block-sum
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
    Time complexity: O(m*n)
    Space complexity: O(m*n)
*/

class Solution
{
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
  {
    const int rows = mat.size();
    const int cols = mat[0].size();

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));

    for (int row = 1; row <= rows; ++row)
      for (int col = 1 ; col <= cols; ++col)
        dp[row][col] = dp[row - 1][col] + dp[row][col - 1] + mat[row - 1][col - 1] - dp[row - 1][col - 1];

    auto ans = mat;
    for (int row = 1; row <= rows; ++row)
      for (int col = 1; col <= cols; ++col)
      {
        int x1 = max(1, col - K);
        int x2 = min(cols, col + K);
        int y1 = max(1, row - K);
        int y2 = min(rows, row + K);
        ans[row - 1][col - 1] = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
      }
    return ans;
  }
};