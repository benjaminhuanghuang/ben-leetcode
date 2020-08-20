/*
1220. Count Vowels Permutation

Level: Hard

https://leetcode.com/problems/count-vowels-permutation
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
  int countVowelPermutation(int n)
  {
    constexpr int kMod = 1e9 + 7;
    vector<vector<long>> dp(n + 1, vector<long>(5));
    fill(begin(dp[1]), end(dp[1]), 1);
    // 0: a, 1: e, 2: i, 3: o, 4: u
    for (int i = 2; i <= n; ++i)
    {
      dp[i][1] += dp[i - 1][0]; // a -> e

      dp[i][0] += dp[i - 1][1]; // e -> a
      dp[i][2] += dp[i - 1][1]; // e -> i

      for (int j = 0; j < 5; ++j)
      {
        if (j == 2)
          continue;
        dp[i][j] += dp[i - 1][2]; // i -> *
      }

      dp[i][2] += dp[i - 1][3]; // o -> i
      dp[i][4] += dp[i - 1][3]; // o -> u

      dp[i][0] += dp[i - 1][4]; // u -> a

      for (int j = 0; j < 5; ++j)
        dp[i][j] %= kMod;
    }
    return accumulate(begin(dp[n]), end(dp[n]), 0L) % kMod;
  }
};