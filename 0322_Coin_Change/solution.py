'''
322. Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the
fewest number of coins that you need to make up that amount.

If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
'''
import sys


class Solution(object):
    # dp[i] = coin count of amount i
    # dp[i + coins[j]]= min(dp[i + coins[j]], dp[i] + 1)
    # Time limit exceeded
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [0x7fffffff] * (amount + 1)
        dp[0] = 0

        for i in xrange(1, amount + 1):
            for coin in coins:
                if i >= coin and dp[i - coin] != 0x7fffffff:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return dp[amount] if dp[amount] != 0x7fffffff else -1

    def coinChange_my(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [0x7fffffff] * (amount + 1)
        dp[0] = 0

        for i in xrange(1, amount + 1):
            for coin in coins:
                if i >= coin and dp[i - coin] != 0x7fffffff:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return dp[amount] if dp[amount] != 0x7fffffff else -1

    # http://freecoder.com.cn/?p=116
    def coinChange_2(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [0x7fffffff] * (amount + 1)
        dp[0] = 0
        coins.sort()
        for i in range(0, amount + 1):
            if dp[i] == 0x7fffffff:
                continue
            for coin in coins:
                if i + coin <= amount:
                    dp[i + coin] = min(dp[i + coin], dp[i] + 1)
                else:
                    # coins.sort() is needed for here
                    break
        return dp[amount] if dp[amount] != 0x7fffffff else -1


s = Solution()
# print s.coinChange_2([1, 2, 5], 11)
print s.coinChange_2([474, 83, 404, 3], 264)
