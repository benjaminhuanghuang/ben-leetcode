/*
1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

Level: Medium

https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1292-maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
*/

class Solution
{
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold)
  {
    const int m = mat.size();
    const int n = mat[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int y = 1; y <= m; ++y)
      for (int x = 1; x <= n; ++x)
        dp[y][x] = dp[y][x - 1] + dp[y - 1][x] - dp[y - 1][x - 1] + mat[y - 1][x - 1];

    auto rangeSum = [&](int x1, int y1, int x2, int y2) {
      return dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1];
    };

    int ans = 0;
    for (int y = 1; y <= m; ++y)
      for (int x = 1; x <= n; ++x)
        for (int k = ans; y + k <= m && x + k <= n; ++k)
        {
          if (rangeSum(x, y, x + k, y + k) > threshold)
            break;
          ans = max(ans, k + 1);
        }
    return ans;
  }
};