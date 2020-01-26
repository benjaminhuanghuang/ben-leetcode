class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        prev = n % 2
        n = n / 2
        while n > 0:
            curr = n % 2
            if curr == prev:
                return False
            prev = curr
            n = n / 2
        return True


s = Solution()
# print s.hasAlternatingBits(5)
print s.hasAlternatingBits(4)
