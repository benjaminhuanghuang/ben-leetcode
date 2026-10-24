'''
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right
corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
'''


class Solution(object):
    # dp[x][y] = dp[x][y-1] + dp[x-1][y]
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m < 1 or n < 1:
            return 0

        path = [[0 for i in range(m)] for j in range(n)]
        for i in range(n):
            path[i][0] = 1
        for j in range(m):
            path[0][j] = 1

        for i in range(1, n):
            for j in range(1, m):
                path[i][j] = path[i - 1][j] + path[i][j - 1]

        return path[-1][-1]
