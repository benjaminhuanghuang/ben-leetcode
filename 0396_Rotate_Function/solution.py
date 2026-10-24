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
