/*
343. Integer Break

Level: Medium

https://leetcode.com/problems/integer-break
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
  int integerBreak(int n)
  {
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)
      dp[i] = 1;

    for (int i = 0; i < n + 1; i++)
    {
      for (int j = 0; j < i + 1; j++)
        if (i + j <= n)
          dp[i + j] = max(max(dp[i], i) * max(dp[j], j), dp[i + j]);
    }
    return dp[n];
  }
};