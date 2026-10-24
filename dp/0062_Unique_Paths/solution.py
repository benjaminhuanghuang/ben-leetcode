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
