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
/*
都分解为1 2 3这样的组合。

如果组合为4，4又可以分解为2 + 2，如果组合为5，5又可以分解为2 + 3。

如果一个数分解后可以写成全是2或全是3，那么全是3的乘积肯定比全是2的大。
*/
class Solution_2
{
public:
  int integerBreak(int n)
  {
    if (n <= 3)
      return n - 1;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; ++i)
    {
      dp[i] = max(2 * dp[i - 2], 3 * dp[i - 3]);
    }

    return dp[n];
  }
};