'''
168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z

    27 -> AA
    28 -> AB

'''


class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        base = ord('A')
        result = ''
        while n:
            result = chr(base + (n - 1) % 26) + result
            n = (n - 1) / 26
        return result
