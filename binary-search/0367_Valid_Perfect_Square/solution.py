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
