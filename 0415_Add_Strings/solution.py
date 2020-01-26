'''
415. Add Strings

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
'''


class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i1 = len(num1) - 1
        i2 = len(num2) - 1
        carry = 0
        res = ""
        while i1 >= 0 or i2 >= 0:
            v1 = int(num1[i1]) if i1 >= 0 else 0
            v2 = int(num2[i2]) if i2 >= 0 else 0
            sum = (v1 + v2 + carry) % 10
            carry = (v1 + v2 + carry) / 10
            res = str(sum) + res
            i1 -= 1
            i2 -= 1
        if carry > 0:
            res = str(carry) + res
        return res
