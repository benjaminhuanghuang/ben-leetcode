'''
123. Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

'''


class Solution(object):
    # https://www.hrwhisper.me/leetcode-best-time-to-buy-and-sell-stock-i-ii-iii-iv/
    # dp[i] is the max profit on day i
    # money is max price
    #
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        n = len(prices)
        dp, money, profit = [], prices[0], 0
        for i in range(n):
            profit = max(profit, prices[i] - money)
            money = min(money, prices[i])
            dp.append(profit)

        i, ans, money, profit = n - 1, dp[n - 1], prices[n - 1], 0
        while i >= 0:
            profit = max(profit, money - prices[i])
            money = max(money, prices[i])
            ans = max(ans, dp[i] + profit)
            i -= 1
        return ans

    # https://shenjie1993.gitbooks.io/leetcode-python/content/123%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III.html
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        total_max_profit = 0
        n = len(prices)
        first_profits = [0] * n
        min_price = float('inf')

        for i in range(n):
            min_price = min(min_price, prices[i])
            total_max_profit = max(total_max_profit, prices[i] - min_price)
            first_profits[i] = total_max_profit

        max_profit = 0
        max_price = float('-inf')
        for i in range(n - 1, 0, -1):
            max_price = max(max_price, prices[i])
            max_profit = max(max_profit, max_price - prices[i])
            total_max_profit = max(total_max_profit, max_profit + first_profits[i - 1])
        return total_max_profit

    # http://www.mamicode.com/info-detail-1244703.html
    # max profit = max(dp[:i], dp[i:])
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        size = len(prices)
        if size == 0:
            return 0
        first, second = [0 for i in range(size)], [0 for i in range(size + 1)]

        min_price = prices[0]
        for i in range(size):
            if prices[i] <= min_price:
                min_price = prices[i]
                first[i] = first[i - 1]
            first[i] = max(prices[i] - min_price, first[i - 1])

        maxp = prices[size - 1]
        j = size - 1
        while j >= 0:
            if prices[j] >= maxp:
                maxp = prices[j]
            second[j] = max(second[j + 1], maxp - prices[j])
            j -= 1

        ans = 0
        for i in range(size):
            ans = max(ans, first[i] + second[i + 1])
        return ans

    # http://www.tangjikai.com/algorithms/leetcode-123-best-time-to-buy-and-sell-stock-iii1
    # The first pass we can record the maximum profit from 0 to i - 1, preProfit[i].
    # The second reversed pass we can record the profit from i to n - 1, postProfit[i].
    # Maximum profit = max(preProfit[i] + postProfit[i]), i < n.
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if not n or n < 2:
            return 0

        dp = [0] * n

        min_price = prices[0]
        for i in range(1, n):
            dp[i] = max(dp[i - 1], prices[i] - min_price)
            min_price = min(min_price, prices[i])

        max_price = prices[-1]
        for i in range(n - 2, -1, -1):
            if max_price > prices[i]:
                dp[i] += max_price - prices[i]
            max_price = max(max_price, prices[i])

        return max(dp)