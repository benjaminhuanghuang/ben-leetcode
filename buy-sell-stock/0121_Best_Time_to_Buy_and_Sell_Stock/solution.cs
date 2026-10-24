using System;

public class Solution121 {
    public int MaxProfit(int[] prices) {
        int maxProfit = 0;
        int lowestPrice = Int32.MaxValue;
        for(int i=0; i<prices.Length; i++)
        {
            int profit = prices[i] - lowestPrice;
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
            if (prices[i] < lowestPrice)
            {
                lowestPrice = prices[i];
            }
        }
        return maxProfit;
    }
}