package cn.huang.leetcode;
/*
122. Best Time to Buy and Sell Stock II

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy
one and sell one share of the stock multiple times).


 */
public class LC_0122_BestTimetoBuyandSellStock_II {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            int diff = prices[i+1] - prices[i];
            if (diff > 0) {
                profit += diff;
            }
        }
        return profit;
    }
}
