/*
712. Minimum ASCII Delete Sum for Two Strings

Level: Medium

https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings
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
  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-712-minimum-ascii-delete-sum-for-two-strings/

  DP

  Time complexity: O(l1 * l2)

  Space complexity: O(l1 * l2)
*/

class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    const int l1 = s1.length();
    const int l2 = s2.length();
    // dp[i][j] := min delete sum of (s1.substr(0, i), s2.substr(0, j))
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    for (int i = 1; i <= l1; ++i)
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
    for (int j = 1; j <= l2; ++j)
      dp[0][j] = dp[0][j - 1] + s2[j - 1];
    for (int i = 1; i <= l1; ++i)
      for (int j = 1; j <= l2; ++j)
        if (s1[i - 1] == s2[j - 1])
          // keep s1[i - 1] and s2[j - 1]
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1],  // delete s1[i - 1]
                         dp[i][j - 1] + s2[j - 1]); // delete s2[j - 1]
    return dp[l1][l2];
  }
};

/*
Recursion + Memorization

Time complexity: O(l1 * l2)

Space complexity: O(l1 * l2)
*/

class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    const int l1 = s1.length();
    const int l2 = s2.length();
    m_ = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, INT_MAX));
    return dp(s1, l1, s2, l2);
  }

private:
  int dp(const string &s1, int i, const string &s2, int j)
  {
    if (i == 0 && j == 0)
      return 0;
    if (m_[i][j] != INT_MAX)
      return m_[i][j];
    if (i == 0) // s1 is empty.
      return m_[i][j] = dp(s1, i, s2, j - 1) + s2[j - 1];
    if (j == 0) // s2 is empty
      return m_[i][j] = dp(s1, i - 1, s2, j) + s1[i - 1];
    if (s1[i - 1] == s2[j - 1]) // skip s1[i-1] / s2[j-1]
      return m_[i][j] = dp(s1, i - 1, s2, j - 1);
    return m_[i][j] = min(dp(s1, i - 1, s2, j) + s1[i - 1],  // del s1[i-1]
                          dp(s1, i, s2, j - 1) + s2[j - 1]); // del s2[j-1]
  }
  vector<vector<int>> m_;
};
