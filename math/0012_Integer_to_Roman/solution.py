'''
12. Integer to Roman

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.


reference
    13. Roman to Integer

'''


class Solution(object):

    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        # ROMAN = {
        #      'I': 1,
        #      'V': 5,
        #      'X': 10,
        #      'L': 50,
        #      'C': 100,
        #      'D': 500,
        #      'M': 1000
        #  }
        ROMAN = ["I", "V", "X", "L", "C", "D", "M"]

        result = ""
        scale = 1000

        for i in xrange(6, -1, -2):  # M, C, X, I
            digit = num / scale
            if 0 < digit and digit <= 3:
                result += (ROMAN[i] * digit)
            elif digit == 4:
                result += (ROMAN[i])
                result += (ROMAN[i + 1])
            elif digit == 5:
                result += (ROMAN[i + 1])
            elif 6 <= digit and digit <= 8:
                result += (ROMAN[i + 1])
                result += (ROMAN[i] * (digit - 5))
            elif digit == 9:
                result += (ROMAN[i])
                result += (ROMAN[i + 2])
            num = num % scale
            scale = scale / 10

        return result


s = Solution()
print s.intToRoman(8)
