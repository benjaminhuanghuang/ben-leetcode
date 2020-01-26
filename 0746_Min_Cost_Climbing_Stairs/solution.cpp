/*
746. Min Cost Climbing Stairs

https://leetcode.com/problems/min-cost-climbing-stairs/
*/
#include <vector>

using namespace std;
/*
    dp[i]表示从第i阶跳出去的最小花费。比如从第0阶跳出去的最小花费是cost[0]，从第1阶跳出去的最小花费是cost[1]。
    dp[i] = min(dp[i-1], dp[i-2]) + cost[i]。
    结果就返回从楼梯顶（第cost.length阶）跳出去的花费
     */
class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    vector<int> dp(cost.size() + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < dp.size(); i++)
    {
      int cur = i == cost.size() ? 0 : cost[i];
      dp[i] = min(dp[i - 1], dp[i - 2]) + cur;
    }
    return dp[cost.size()];
  }
};