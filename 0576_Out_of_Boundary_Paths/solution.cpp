/*
576. Out of Boundary Paths

Level: Medium

https://leetcode.com/problems/out-of-boundary-paths
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-576-out-of-boundary-paths/

  Solution: 
*/

class Solution
{
public:
  int findPaths(int m, int n, int N, int i, int j)
  {
    constexpr int kMod = 1000000007;
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
    vector<int> dirs{-1, 0, 1, 0, -1};
    for (int s = 1; s <= N; ++s)
      for (int y = 0; y < m; ++y)
        for (int x = 0; x < n; ++x)
          for (int d = 0; d < 4; ++d)
          {
            int tx = x + dirs[d];
            int ty = y + dirs[d + 1];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m)
              dp[s][y][x] += 1;
            else
              dp[s][y][x] = (dp[s][y][x] + dp[s - 1][ty][tx]) % kMod;
          }
    return dp[N][i][j];
  }
};