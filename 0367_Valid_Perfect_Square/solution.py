'''
367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
'''


class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 1:
            return False
        if num == 1:
            return True

        left = 0
        right = num / 2
        while left <= right:
            mid = (left + right) >> 1
            val = mid * mid
            if val == num:
                return True
            else:
                if val > num:
                    right = mid - 1
                else:
                    left = mid + 1
        return False
