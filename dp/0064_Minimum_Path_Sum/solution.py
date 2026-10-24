'''
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the
sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
'''


class Solution(object):
    # dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
    def minPathSum_1(self, grid):
        for i in xrange(1, len(grid)):
            grid[i][0] += grid[i-1][0]
        for j in xrange(1, len(grid[0])):
            grid[0][j] += grid[0][j-1]
        for i in xrange(1, len(grid)):
            for j in xrange(1, len(grid[0])):
                grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j]
        return grid[-1][-1]

    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dp = [0] * len(grid)
        dp[0] = grid[0][0]
        for i in range(1, len(grid)):
            dp[i] = dp[i - 1] + grid[i][0]
        for j in range(1, len(grid[0])):
            for i in range(len(grid)):
                dp[i] = min(dp[i], dp[i - 1]) + grid[i][j] if i > 0 else dp[i] + grid[i][j]
        return dp[len(grid) - 1]

s = Solution()
print s.minPathSum_1([[1]])