/*
1143. Longest Common Subsequence

Level: Medium

https://leetcode.com/problems/longest-common-subsequence
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
  Use dp[i][j] to represent the length of longest common sub-sequence of text1[0:i] and text2[0:j]
  dp[i][j] = dp[i – 1][j – 1] + 1 if text1[i – 1] == text2[j – 1] else max(dp[i][j – 1], dp[i – 1][j])

  Time complexity: O(mn)
  Space complexity: O(mn) -> O(n)
*/

class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (text1[i] == text2[j])
          dp[i + 1][j + 1] = dp[i][j] + 1;
        else
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    return dp[m][n];
  }
};