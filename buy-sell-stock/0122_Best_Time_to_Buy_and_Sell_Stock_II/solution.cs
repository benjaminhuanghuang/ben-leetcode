using System;

public class Solution122 {
    public int MaxProfit(int[] prices) {
        int profit = 0;
        for(int i=1; i<prices.Length; i++)
        {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0)
            {
                profit += diff;
            }
        }
        return profit;
    }
}