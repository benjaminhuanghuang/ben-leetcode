'''
201. Bitwise AND of Numbers Range


Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

'''


class Solution(object):
    # http://www.cnblogs.com/grandyang/p/4431646.html
    # result = the common left part of all number in the range
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        p = 0
        while m != n:
            m >>= 1
            n >>= 1
            p += 1
        return m << p
