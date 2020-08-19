/*
174. Dungeon Game

Level: Hard

https://leetcode.com/problems/dungeon-game
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
  https://www.cnblogs.com/grandyang/p/4233035.html
  DP
*/

class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; --i)
    {
      for (int j = n - 1; j >= 0; --j)
      {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
};