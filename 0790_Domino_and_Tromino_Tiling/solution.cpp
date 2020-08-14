/*
790. Domino and Tromino Tiling

Level: Medium

https://leetcode.com/problems/domino-and-tromino-tiling
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-790-domino-and-tromino-tiling/
*/

class Solution
{
public:
  int numTilings(int N)
  {
    constexpr int kMod = 1000000007;
    vector<vector<long>> dp(N + 1, vector<long>(3, 0));
    dp[0][0] = dp[1][0] = 1;
    for (int i = 2; i <= N; ++i)
    {
      dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % kMod;
      dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % kMod;
      dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % kMod;
    }

    return dp[N][0];
  }
};