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
