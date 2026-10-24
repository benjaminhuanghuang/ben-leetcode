'''
172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in "logarithmic time complexity".


Hint:
    n! = 1*2*3*4... *n
    The number of trailing 0 = the count of 2*5 pair

reference:
    https://unnamed42.github.io/2015-12-03-Leetcode-172-Factorial-Trailing-Zeroes.html
'''


class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count_five = 0;
        while (n > 0):
            k = n / 5
            count_five += k
            n = k

        return count_five

    # when n = 2622, time limit exceeded
    def trailing_zeroes_naive(self, n):
        factorial = 1
        while n > 0:
            factorial = factorial * n
            n -= 1

        count_zero = 0
        while factorial > 0:
            if factorial % 10 == 0:
                factorial = factorial / 10
                count_zero += 1
            else:
                break

        return count_zero


s = Solution()
print s.trailingZeroes(2622)