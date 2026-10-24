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
