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
