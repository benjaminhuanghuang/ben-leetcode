'''
29. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

'''


class Solution(object):
    # Time Limit Exceeded, can not pass -2147483648 -1
    def divide_niave(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        is_nagetive = (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0)

        a = abs(dividend)
        b = abs(divisor)

        if a < b:
            return 0

        res = 0
        sum = b
        while sum <= a:
            sum += b
            res += 1

        if is_nagetive:
            res = 0 - res
        return res

    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        is_nagetive = (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0)

        dividend = abs(dividend)
        divisor = abs(divisor)

        if dividend < divisor:
            return 0

        res = 0
        while dividend >= divisor:
            sum = divisor
            count = 1
            while (sum << 1) <= dividend:
                sum = sum << 1
                count = count << 1
            dividend -= sum
            res += count

        if is_nagetive:
            res = 0 - res

        if res > 0x7fffffff:
            return 0x7fffffff
        return res


s = Solution()
print s.divide(200, 3)
