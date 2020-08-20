/*
1312. Minimum Insertion Steps to Make a String Palindrome

Level: Hard

https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1312-minimum-insertion-steps-to-make-a-string-palindrome/
  
  Solution: DP

  dp[i][j] := min chars to insert
  dp[j][j] = dp[i-1][j+1] if s[i] == s[j] else min(dp[i+1][j] , dp[i][j-1]) + 1
  base case: dp[i][i] = 0
  ans: dp[0][n-1]

  Time complexity: O(n^2)
  Space complexity: O(n^2)
*/

class Solution
{
public:
  int minInsertions(string s)
  {
    const int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int l = 2; l <= n; ++l)
      for (int i = 0, j = l - 1; j < n; ++i, ++j)
        dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i + 1][j], dp[i][j - 1]) + 1;
    return dp[0][n - 1];
  }
};