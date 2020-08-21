/*
1510. Stone Game IV

Level: Hard

https://leetcode.com/problems/stone-game-iv
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

  Let dp[i] be whether Alice and win starting with i stones.

  dp[i] = true    // If any dp[i - j * j] is false
        = false   // otherwise
        where 1 <= j * j <= i  -- the stone taken by Bob.

*/

class Solution
{
public:
  bool winnerSquareGame(int n)
  {
    vector<bool> dp(1);
    if (dp.size() <= n)
      dp.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j * j <= i && !dp[i]; ++j)
      {
        dp[i] = !dp[i - j * j];
      }
    }
    return dp[n];
  }
};