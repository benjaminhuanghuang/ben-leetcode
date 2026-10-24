using System;

public class Solution188 {
    // dp[i, j] to store up to ith, the j transactions max profit.
    // https://miafish.wordpress.com/2015/05/05/leetcode-ojc-best-time-to-buy-and-sell-stock-iv/
    public int MaxProfit(int k, int[] prices) {
        if (k >= prices.Length / 2)
        {
            return maxProfit_all(prices);
        }

        var dp = new int[prices.Length + 1, k + 1];

        dp[0, 0] = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < prices.Length; j++)
            {                     
                var max = 0;                     
                for (int l = j - 1; l >= 0; l--)
                {
                    max = Math.Max(max, dp[l, i] + (prices[j] - prices[l]));
                }

                dp[j + 1, i + 1] = Math.Max(dp[j, i+1], Math.Max(dp[j + 1, i], max));
            }
        }

        return dp[prices.Length, k];
    }

    public int maxProfit_all(int[] prices)
    {
        int n = prices.Length;
        int sum = 0;
        for (int i = 1; i < n; i++)
        {                 
            if (prices[i] > prices[i - 1])
            {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
}