'''
121. Best Time to Buy and Sell Stock

Say you have an array for which the i-th element is the price of a given stock on day i.

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

'''
import sys


class Solution_my(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maxProfit = 0
        lowest = prices[0]
        for i in range(1, len(prices)):
            curr_p = prices[i]
            if curr_p - lowest > maxProfit:
                maxProfit = curr_p - lowest
            if curr_p < lowest:
                lowest = curr_p
        return maxProfit


# O(n) time, O(1) space
def max_profit(prices):
    profit = 0
    lowest_price = sys.maxint
    for curr_price in prices:
        if curr_price - lowest_price > profit:
            profit = curr_price - lowest_price
        if curr_price < lowest_price:
            lowest_price = curr_price
    return profit


prices = [7, 6, 4, 3, 1]
prices = [50, 55, 10, 9, 8]
print max_profit(prices)
