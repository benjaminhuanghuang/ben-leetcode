package cn.huang.leetcode;

/*
    746. Min Cost Climbing Stairs
 */
public class LC_0746_MinCostClimbingStairs {
    /*
    dp[i]表示跳到第i阶所需的最小花费
    dp[i] = min(dp[i-1] + cost[i - 1], dp[i-2] + cost[i-2])
     */
    public int minCostClimbingStairs(int[] cost) {
        return Math.min(minCost(cost, 0), minCost(cost, 1));
    }

    public int minCost(int[] cost, int start) {
        int[] dp = new int[cost.length + 1];
        dp[start] = 0;
        dp[start + 1] = cost[start];
        for (int i = start + 2; i < dp.length; i++) {
            dp[i] = Math.min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.length];
    }

    /*
    dp[i]表示从第i阶跳出去的最小花费。比如从第0阶跳出去的最小花费是cost[0]，从第1阶跳出去的最小花费是cost[1]。
    dp[i] = min(dp[i-1], dp[i-2]) + cost[i]。
    结果就返回从楼梯顶（第cost.length阶）跳出去的花费
     */
    public int minCostClimbingStairs_better(int[] cost) {
        int[] dp = new int[cost.length + 1];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < dp.length; i++) {
            int cur = i == cost.length ? 0 : cost[i];
            dp[i] = Math.min(dp[i - 1], dp[i - 2]) + cur;
        }
        return dp[cost.length];
    }
}
