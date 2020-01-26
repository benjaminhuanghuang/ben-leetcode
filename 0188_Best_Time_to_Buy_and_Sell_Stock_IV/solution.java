package cn.huang.leetcode;

/*
188. Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

 */
public class LC_0188_BestTimetoBuyandSellStock_IV {
    /*
    https://www.youtube.com/watch?v=t92vU3NvZ8k
     */
    public int maxProfit(int k, int[] prices) {
        if (k >= prices.length / 2) {
            return helper(prices);
        }

        int[][] dp = new int[prices.length + 1][k + 1];

        dp[0][0] = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < prices.length; j++) {
                int max = 0;
                for (int l = j - 1; l >= 0; l--) {
                    max = Math.max(max, dp[l][i] + (prices[j] - prices[l]));
                }

                dp[j + 1][i + 1] = Math.max(dp[j][i + 1], Math.max(dp[j + 1][i], max));
            }
        }

        return dp[prices.length][k];
    }

    public int helper(int[] prices) {
        int n = prices.length;
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
}
