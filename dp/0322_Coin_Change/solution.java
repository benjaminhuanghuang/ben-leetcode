package cn.huang.leetcode;

/*
322. Coin Change
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
 If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.

 */
public class LC_0322_CoinChange {
    // dp[i] 表示凑齐钱数 i 需要的最少硬币数，凑齐钱数 amount 最少硬币数为：固定钱数为 coins[j] 一枚硬币，
    // 另外的钱数为 amount - coins[j] 它的数量为dp[amount - coins[j]]
    // 则有：dp[i + coins[j] ] = min(dp[i + coins[j] ] , dp[i] + 1）
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        for (int i = 1; i <= amount; i++)
            dp[i] = Integer.MAX_VALUE - 1;

        for (int coin : coins)
            for (int i = coin; i <= amount; i++)
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);

        return dp[amount] == Integer.MAX_VALUE - 1 ? -1 : dp[amount];
    }
}
