package cn.huang.leetcode;
/*
518. Coin Change 2
You are given coins of different denominations and a total amount of money. Write a function to compute the
number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

    0 <= amount <= 5000
    1 <= coin <= 5000
    the number of coins is less than 500
    the answer is guaranteed to fit into signed 32-bit integer


 */
public class LC_0518_CoinChange_2 {
    public int change_naive_dp(int amount, int[] coins) {
        /*
        https://www.youtube.com/watch?v=ZKAILBWl08g
        n = number of types of coins
        m = desired amount

        f[i][j] = the number of combinations to make up amount j with only the first i types of coins

        induction rule is
        f[i][j] = sum(f[i-1, j],
                      f[i-1, j- coins[i-1]
                      ...)

         */
        int[][] dp = new int[coins.length+1][amount+1];
        dp[0][0] = 1;
        for (int i = 1; i <= coins.length; i++) { //跑當前硬幣
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++) { // j 就是錢的金額
                dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);    //後面的意思就是說拿這個硬幣並去查表之前的金額有幾種把它加進來
            }
        }
        return dp[coins.length][amount];
    }
    //https://medium.com/@william456821/dp-518-coin-change-2-java-eebcb202bf94
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
                //dp[i] = dp[i] + dp[i-coin];
            }
        }
        return dp[amount];
    }
}
