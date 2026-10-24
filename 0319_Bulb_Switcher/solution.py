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
