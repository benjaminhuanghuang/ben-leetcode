'''
319. Bulb Switcher

There are n bulbs that are initially off. You first turn on all the bulbs.
Then, you turn off every second bulb.
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on).

For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.
Find how many bulbs are on after n rounds.

Example:

Given n = 3.

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off].

So you should return 1, because there is only one bulb is on.
'''


class Solution(object):
    # http://www.cnblogs.com/grandyang/p/5100098.html
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 1:
            return 0

        return int(n ** 0.5)

    #  Time limit exceeded
    def bulb_switch_naive(self, n):
        if n < 0:
            return 0

        bulbs = [0] * n
        for i in xrange(n / 2 + 1):
            for j in xrange(i, n, i + 1):
                bulbs[j] = (bulbs[j] + 1) % 2

        # Round after n / 2 + 1, just switch 1 bulb each time
        for i in xrange(n / 2 + 1, n):
            bulbs[i] = (bulbs[i] + 1) % 2

        count = sum(bulbs)
        return count


s = Solution()
print s.bulb_switch_naive(3)
