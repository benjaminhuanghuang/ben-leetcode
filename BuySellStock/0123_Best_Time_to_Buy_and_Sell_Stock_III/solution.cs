/*
123. Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

https://miafish.wordpress.com/2015/02/04/leetcode-oj-c-best-time-to-buy-and-sell-stock-iii/

*/
using System;

public class Solution123 {
    public int MaxProfit(int[] prices) {
        var maxProfitForTwoTrades = 0;
        var minPrice = int.MaxValue;

        // get each day max profit
        var profit = new int[prices.Length];
        for (int index = 0; index < prices.Length; index++)
        {
            minPrice = Math.Min(minPrice, prices[index]);
            profit[index] = prices[index] - minPrice;
        }
        int i;
        for (i = 1; i < profit.Length; i++)
        {
            // whenever profit is down, calculate two trades
            if (profit[i] < profit[i - 1])
            {
                var firstTrade = profit[i - 1];
                var secondTrade = this.maxProfit(prices, i);

                if (secondTrade <= 0)
                {
                    secondTrade = 0;
                }                              
                
                if (firstTrade + secondTrade > maxProfitForTwoTrades)
                {
                    maxProfitForTwoTrades = firstTrade + secondTrade;
                }
            }
        }

        if (i == profit.Length && maxProfitForTwoTrades == 0)
        {
            maxProfitForTwoTrades = profit[profit.Length - 1];
        }

        return maxProfitForTwoTrades;
    }

    public int maxProfit(int[] prices, int index)
    {
        var maxProfit = 0;
        var minPrice = int.MaxValue;
        for (int i = index; i < prices.Length; i++)
        {
            minPrice = Math.Min(minPrice, prices[i]);
            maxProfit = Math.Max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
}