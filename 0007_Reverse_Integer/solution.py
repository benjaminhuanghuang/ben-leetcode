'''
7. Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
'''
import sys


class Solution(object):
    # naive solution:
    # input 1534236469
    # Output: 9646324351
    # Expected: 0
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        max_int = 2 ** 31 - 1
        sign = 1
        if x < 0:
            sign = -1
        result = 0
        x = abs(x)
        while x != 0:
            if result > max_int / 10:
                return 0
            result = result * 10 + x % 10
            x = x / 10
        result *= sign
        return result