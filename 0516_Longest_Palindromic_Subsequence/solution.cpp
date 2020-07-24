/*
516. Longest Palindromic Subsequence

Level: Medium

https://leetcode.com/problems/longest-palindromic-subsequence
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
  Solution:  DP


  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-516-longest-palindromic-subsequence/
*/

class Solution
{
public:
  int longestPalindromeSubseq(string s)
  {
    const int n = s.length();
    vector<int> dp0(n); // sols of len = l
    vector<int> dp1(n); // sols of len = l - 1
    vector<int> dp2(n); // sols of len = l - 2
    for (int l = 1; l <= n; ++l)
    {
      for (int i = 0; i <= n - l; ++i)
      {
        int j = i + l - 1;
        if (i == j)
        {
          dp0[i] = 1;
          continue;
        }
        if (s[i] == s[j])
          dp0[i] = dp2[i + 1] + 2;
        else
          dp0[i] = max(dp1[i + 1], dp1[i]);
      }
      dp0.swap(dp1);
      dp2.swap(dp0);
    }
    return dp1[0];
  }
};