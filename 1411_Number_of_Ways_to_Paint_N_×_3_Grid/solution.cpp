/*
1411. Number of Ways to Paint N × 3 Grid

Level: Hard

https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid
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
  int numOfWays(int n)
  {
    constexpr int kMod = 1e9 + 7;
    // dp[i][0] = # of ways to paint i rows with i-th row has 2 colors (e.g. 121)
    // dp[i][1] = # of ways to paint i rows with i-th row has 3 colors (e.g. 123)
    // dp[1][0] = dp[1][1] = 6.
    vector<vector<long>> dp(n + 1, vector<long>(2, 6));
    for (int i = 2; i <= n; ++i)
    {
      // 121 => 2 colors x 3 {212, 232, 313}, 3 colors x 2 {213, 312}
      // 123 => 2 colors x 2 {212, 232}, 3 colors x 2 {231, 312}
      dp[i][0] = (dp[i - 1][0] * 3 + dp[i - 1][1] * 2) % kMod;
      dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1] * 2) % kMod;
    }
    return (dp[n][0] + dp[n][1]) % kMod;
  }
};