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
  f[i][j] = sum(f[i-1][j],               // use coins[i-1]  0 times
                f[i-1][j-conis[j-1]]     // use coins[i-1]  1 times
                f[i-1][j-conis[j-1]*2]   // use coins[i-1]  2 times
                f[i-1][j-conis[j-1]*3]   // use coins[i-1]  3 times
                ...
               )

  f[i][j] = sum(f[i-1][j-k*conis[i-1]])      0 < k <= j/conis[i-1]             
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
      for (int j = 0; j <= amount; ++j)
      {
        dp[i][j] = 0;
        for (int k = 0; k * coins[i - 1] < j; k++)
        {
          dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
        }
      }
    }
    return dp[coins.size()][amount];
  }
};

/*
  https://www.cnblogs.com/grandyang/p/7669088.html

  二维的 dp 数组，其中 dp[i][j] 表示用前i个硬币组成钱数为j的不同组合方法，
  怎么算才不会重复，也不会漏掉呢？我们采用的方法是一个硬币一个硬币的增加，
  每增加一个硬币，都从1遍历到 amount，对于遍历到的当前钱数j，组成方法就是
  不加上当前硬币的拼法 dp[i-1][j] + 去掉当前硬币值的钱数的组成方法，当然钱数j要大于当前硬币值，：
    dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0)
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
        // 使用当前coin的组合数量
        int useCurrCoin = j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0;
        dp[i][j] = dp[i - 1][j] + useCurrCoin;
      }
    }
    return dp[coins.size()][amount];
  }
};

/*
  Solution: 

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-518-coin-change-2/

  Transition 1:

    Let us use dp[i][j] to denote the number of ways to sum up to amount j using first i kind of coins.

    dp[i][j] = dp[i – 1][j – coin] + dp[i – 1][j – 2* coin] + …

    Time complexity: O(n*amount^2) TLE

    Space complexity: O(n*amount) -> O(amount)

  Transition 2:

    Let us use dp[i] to denote the number of ways to sum up to amount i.

    dp[i + coin] += dp[i]
    组成amount大小的硬币的组合数等于组成amount - c大小的硬币数 (for c in coins) 之和。
    Time complexity: O(n*amount)

    Space complexity:  O(amount)
*/

class Solution
{
public:
  int change(int amount, vector<int> &coins)
  {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // only 1 way to make ammount 0
    for (const int coin : coins)
      for (int i = 0; i <= amount - coin; ++i)
        dp[i + coin] += dp[i];
    return dp[amount];
  }
};