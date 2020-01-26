'''
479. Largest Palindrome Product [Yahoo]

Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
'''


class Solution(object):
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 9

        high = 10 ** (2 * n) - 1
        low = 10 ** n
        res = 0
        for i in range(high, low, -1):
            if self.isPalindrome(i) and self.isProduct(i, n):
                res = i
                break
        return res % 1337

    def isPalindrome(self, num):
        rev = 0
        x = num
        while x > 0:
            rev = 10 * rev + x % 10
            x = x / 10
        return num == rev

    def isProduct(self, num, n):
        for i in range(10 ** n - 1, 10 ** (n - 1), -1):
            if num % i == 0 and num / i < 10 ** n:
                return True
        return False


s = Solution()
print s.largestPalindrome(4)
