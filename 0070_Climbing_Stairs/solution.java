package cn.huang.leetcode;

/*
    70. Climbing Stairs
 */
public class LC_0070_ClimbingStairs {
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    public int climbStairs_better(int n) {
        if (n <= 1)
            return 1;
        int oneStep = 1;
        int twoStep = 1;
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = res;
        }

        return res;
    }
}
