'''
50. Pow(x, n)

Implement pow(x, n).
'''


class Solution(object):
    # 10 = (1010)b = 2^3*1 + 2^2*0 + 2^1*1 + 2^0*0
    # x^10 = x^(2^3*1) * x^(2^2*0) * x^(2^1*1) * x^(2^0*0)

    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        neg_pow = n < 0
        n = abs(n)
        res = 1
        for i in xrange(31, -1, -1):
            res = res * res
            if n & (1 << i):
                res = res * x

        if neg_pow:
            res = 1 / res
        return res

    def myPow_2(self, x, n):
        if n >= 0:
            return self.pow_helper(x, n)
        else:
            return 1 / self.pow_helper(x, -n)

    # x^n = x^(n/2)*x^(n/2)*x^(n%2)
    def pow_helper(self, x, n):
        if n == 0:
            return 1
        res = self.pow_helper(x, n / 2)
        res *= res
        if n % 2 == 1:
            res *= x
        return res
