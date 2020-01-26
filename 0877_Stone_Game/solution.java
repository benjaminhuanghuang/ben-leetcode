package cn.huang.leetcode;

/*
877. Stone Game
 */
public class LC_0877_StoneGame {
    private int[] p;        //copy of piles
    private int[][] dp;     //solved subproblems

    public boolean stoneGame(int[] piles) {
        p = piles;
        int len = piles.length;
        dp = new int[len][len];
        return dp(0, len - 1) > 0;
    }

    private int dp(int lo, int hi) {
        if (lo == hi) {
            return 0;
        }
        if (dp[lo][hi] != 0) {
            return dp[lo][hi];
        }
        int res = 0;
        if ((hi - lo + 1) % 2 == 0) {
            res = Math.max(dp(lo + 1, hi) + p[lo], dp(lo, hi - 1) + p[hi]);
        } else {
            res = Math.min(dp(lo + 1, hi) - p[lo], dp(lo, hi - 1) - p[hi]);
        }
        dp[lo][hi] = res;
        return res;
    }
}
