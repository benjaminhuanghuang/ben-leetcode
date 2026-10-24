using System;
public class Solution322 {
    // dp[i] 表示凑齐钱数 i 需要的最少硬币数，那么凑齐钱数 amount 最少硬币数为：钱数为 coins[j]的一枚硬币，
    // 另外的钱数为 amount - coins[j] 它的数量为dp[amount - coins[j]]
    // 则有：dp[i + coins[j] ] = min(dp[i + coins[j] ] , dp[i] + 1）
    public int CoinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];  
        for (int i = 1; i <= amount; i++) 
            dp[i] = Int32.MaxValue - 1;

        foreach(int coin in coins)  
            for (int i = coin; i <= amount; i++)  
                dp[i] = Math.Min(dp[i], dp[i - coin] + 1);  

        return dp[amount] == Int32.MaxValue -1 ? -1 : dp[amount];  
    }
}