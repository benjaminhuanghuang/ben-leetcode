# 121. Best Time to Buy and Sell Stock

Difficulty: Easy

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock>

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

## Explain

卖出的那一天，最优的买入点一定是它之前出现过的最低价那一天
不可能在卖出日之后买入，也不会选一个比历史最低价更高的买入点
只需要遍历一次，边走边更新"历史最低点"，边尝试"今天卖出能赚多少
