/*
1223. Dice Roll Simulation

Level: Medium

https://leetcode.com/problems/dice-roll-simulation
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

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1223-dice-roll-simulation/
*/

class Solution
{
public:
  int dieSimulator(int n, vector<int> &rollMax)
  {
    constexpr int kMaxRolls = 15;
    constexpr int kMod = 1e9 + 7;

    // dp[i][j][k] := # of sequences ends with k consecutive j after i rolls
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(6, vector<int>(kMaxRolls + 1)));

    for (int j = 0; j < 6; ++j)
      dp[1][j][1] = 1; // 1 step, 1 dice, 1 way

    for (int i = 2; i <= n; ++i)
      for (int j = 0; j < 6; ++j)
        for (int p = 0; p < 6; ++p)
          for (int k = 1; k <= rollMax[p]; ++k)
            if (p != j) // not the same dice
              dp[i][j][1] = (dp[i][j][1] + dp[i - 1][p][k]) % kMod;
            else if (k < rollMax[p]) // same dice, make sure k + 1 <= rollMax
              dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][p][k]) % kMod;

    int ans = 0;
    for (int j = 0; j < 6; ++j)
      for (int k = 1; k <= rollMax[j]; ++k)
        ans = (ans + dp[n][j][k]) % kMod;

    return ans;
  }
};