/*
518. Coin Change 2

Level: Medium

https://leetcode.com/problems/coin-change-2

# 322
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
  n = number of types of coins
  m = desired amount
  f[i][j] = the number of combinations to make up amount j with fist i types of coins

  Induction rule
  f[i][j] = sum(f[i-1][j], 
                f[i-1][j-coins[i-1]],
                f[i-1][j-coins[i-1]*2]
                f[i-1][j-coins[i-1]*3]
                )
*/
class Solution
{
public:
  int change(int amount, vector<int> &coins)
  {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= coins.size(); ++i)
    {
      dp[i][0] = 1;
      for (int j = 1; j <= amount; ++j)
      {
        dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
      }
    }
    return dp[coins.size()][amount];
  }
};

/*
  Solution: 

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-518-coin-change-2/

  Let us use dp[i][j] to denote the number of ways to sum up to amount j using first i kind of coins.

  dp[i][j] = dp[i – 1][j – coin] + dp[i – 1][j – 2* coin] + …

  Time complexity: O(n*amount^2) TLE

  Space complexity: O(n*amount) -> O(amount)
*/

class Solution
{
public:
  int change(int amount, vector<int> &coins)
  {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (const int coin : coins)
      for (int i = 0; i <= amount - coin; ++i)
        dp[i + coin] += dp[i];
    return dp[amount];
  }
};