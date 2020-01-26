'''
166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

'''


class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        res = ''

        if numerator % denominator == 0:
            return str(numerator / denominator)

        if numerator * denominator < 0:
            res += '-'
        n = abs(numerator)
        d = abs(denominator)

        res += str(n / d) + '.'
        n %= d

        i = len(res)
        table = {}

        while n != 0:
            if n not in table:
                table[n] = i
            else:
                i = table[n]
                res = res[:i] + '(' + res[i:] + ')'
                return res

            n *= 10
            res += str(n / d)
            n %= d
            i += 1

        return res


s = Solution()

print s.fractionToDecimal(1, 7)
