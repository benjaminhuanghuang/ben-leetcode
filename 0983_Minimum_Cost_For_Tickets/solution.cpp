/*
983. Minimum Cost For Tickets

Level: Medium

https://leetcode.com/problems/minimum-cost-for-tickets
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-983-minimum-cost-for-tickets/
  
  Solution: DP

  dp[i] := min cost to cover the i-th day
  dp[0] = 0
  dp[i] = min(dp[i – 1] + costs[0], dp[i – 7] + costs[1], dp[i – 30] + costs[2])


*/

class Solution
{
public:
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    vector<int> req(days.back() + 1);
    vector<int> dp(days.back() + 1);
    for (int day : days)
      req[day] = 1;
    dp[0] = 0;
    for (int i = 1; i < dp.size(); ++i)
    {
      if (!req[i])
      {
        dp[i] = dp[i - 1];
        continue;
      }
      dp[i] = dp[i - 1] + costs[0];
      dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
      dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
    }
    return dp.back();
  }
};