/*
650. 2 Keys Keyboard

Level: Medium

https://leetcode.com/problems/2-keys-keyboard
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
  int minSteps(int n)
  {
    if (n == 1)
      return 0;
    int res = n;
    for (int i = n - 1; i > 1; --i)
    {
      if (n % i == 0)
      {
        res = min(res, minSteps(n / i) + i);
      }
    }
    return res;
  }
};

class Solution_DP
{
public:
  int minSteps(int n)
  {
    int dp[n + 1];
    for (int i = 2; i <= n; ++i)
    {
      dp[i] = i;
      for (int j = i - 1; j > 1; --j)
      {
        if (i % j == 0)
        {
          dp[i] = min(dp[i], dp[j] + i / j);
        }
      }
    }
    return dp[n];
  }
};