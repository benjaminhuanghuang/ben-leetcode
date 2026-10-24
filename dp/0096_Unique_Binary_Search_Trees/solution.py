'''
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''


class Solution(object):
    # http://www.csuldw.com/leetcode/Leetcode[96]-Unique%20Binary%20Search%20Trees.html
    # dp[0] = 1
    # dp[1] = 1
    # ...
    # dp[n] = dp[0]* dp[n-1] + dp[1]*dp[n-2] + ... + dp[i]*dp[n-1-i] +... + dp[n-1]*dp[0]
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1  # array is []
        dp[1] = 1  # array has 1 element

        for i in xrange(2, n + 1):
            for j in xrange(0, i):
                dp[i] += dp[j] * dp[i - j - 1]

        return dp[n]
