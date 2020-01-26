'''
69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.
'''


class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """

        if x < 2:
            return x

        left = 1
        right = x / 2

        while left <= right:
            mid = (left + right) / 2
            if (x > mid * mid):
                left = mid + 1
                lastMid = mid
            elif (x < mid * mid):
                right = mid - 1
            else:
                return mid

        return lastMid

s = Solution()
print s.mySqrt(5)