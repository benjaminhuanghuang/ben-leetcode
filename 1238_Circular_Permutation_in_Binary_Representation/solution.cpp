/*
1238. Circular Permutation in Binary Representation

Level: Medium

https://leetcode.com/problems/circular-permutation-in-binary-representation
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
  vector<int> circularPermutation(int n, int start)
  {
    vector<vector<int>> dp(n + 1);
    dp[0] = {0};
    for (int i = 1; i <= n; ++i)
    {
      dp[i] = dp[i - 1];
      for (int j = dp[i - 1].size() - 1; j >= 0; --j)
        dp[i].push_back(dp[i - 1][j] | (1 << (i - 1)));
    }
    for (auto it = begin(dp[n]); it != end(dp[n]); ++it)
      if (*it == start)
      {
        rotate(begin(dp[n]), it, end(dp[n]));
        break;
      }
    return dp[n];
  }
};