/*
1278. Palindrome Partitioning III

Level: Hard

https://leetcode.com/problems/palindrome-partitioning-iii
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1278-palindrome-partitioning-iii/
*/

class Solution
{
public:
  int palindromePartition(string s, int K)
  {
    const int n = s.length();
    vector<vector<int>> cost(n, vector<int>(n));
    for (int l = 2; l <= n; ++l)
      for (int i = 0, j = l - 1; j < n; ++i, ++j)
        cost[i][j] = (s[i] != s[j]) + cost[i + 1][j - 1];

    vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX / 2));
    for (int i = 0; i < n; ++i)
    {
      dp[i][1] = cost[0][i];
      for (int k = 2; k <= K; ++k)
        for (int j = 0; j < i; ++j)
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost[j + 1][i]);
    }
    return dp[n - 1][K];
  }
};