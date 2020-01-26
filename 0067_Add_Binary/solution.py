'''
67. Add Binary  [#2, #43]

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
'''


class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """

        indexa = len(a) - 1
        indexb = len(b) - 1
        carry = 0
        sum = ""
        while indexa >= 0 or indexb >= 0:
            x = int(a[indexa]) if indexa >= 0 else 0
            y = int(b[indexb]) if indexb >= 0 else 0

            sum = str((x + y + carry) % 2) + sum
            carry = (x + y + carry) / 2
            indexa -= 1
            indexb -= 1

        if carry == 1:
            sum = '1' + sum
        return sum
