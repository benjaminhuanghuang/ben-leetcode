'''
396. Rotate Function

Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function"
F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
'''


class Solution(object):
    def maxRotateFunction_naive(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if not A:
            return None

        n = len(A)
        max_f = None
        for i in xrange(n):
            f = self.sum_f(i, A)
            max_f = max(max_f, f) if max_f else f

        return max_f

    def sum_f(self, rotat_point, A):
        n = len(A)
        f = 0
        for i in xrange(n):
            index = (rotat_point + i + n) % n
            f += i * A[index]
        return f

    #  http://bookshadow.com/weblog/2016/09/11/leetcode-rotate-function/
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        size = len(A)
        sums = sum(A)
        f = sum(x * n for x, n in enumerate(A))

        max_f = f
        for x in range(size - 1, 0, -1):
            f += sums - size * A[x]
            max_f = max(max_f, f)
        return max_f


A = [4, 3, 2, 6]
s = Solution()
print s.maxRotateFunction_naive(A)
print s.maxRotateFunction(A)
