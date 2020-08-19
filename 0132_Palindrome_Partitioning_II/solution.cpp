/*
132. Palindrome Partitioning II

Level: Hard

https://leetcode.com/problems/palindrome-partitioning-ii
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

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-132-palindrome-partitioning-ii/
*/

class Solution
{
public:
  int minCut(string s)
  {
    const int n = s.length();
    // valid[i][j] = 1 if s[i~j] is palindrome, otherwise 0
    vector<vector<int>> valid(n, vector<int>(n, 1));

    // dp[i] = min cuts of s[0~i]
    vector<int> dp(n, n);

    for (int l = 2; l <= n; ++l)
      for (int i = 0, j = i + l - 1; j < n; ++i, ++j)
        valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];

    for (int i = 0; i < n; ++i)
    {
      if (valid[0][i])
      {
        dp[i] = 0;
        continue;
      }
      for (int j = 0; j < i; ++j)
        if (valid[j + 1][i])
          dp[i] = min(dp[i], dp[j] + 1);
    }
    return dp[n - 1];
  }
};