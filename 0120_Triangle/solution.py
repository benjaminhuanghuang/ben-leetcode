'''
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

'''


class Solution(object):
    # Did not use adjacent number
    def minimumTotal_my(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle:
            return 0

        row_count = len(triangle)
        dp = [0] * (row_count + 1)
        for row in xrange(row_count):
            dp[row + 1] = dp[row] + min(triangle[row])

        return dp[-1]

    # https://shenjie1993.gitbooks.io/leetcode-python/content/120%20Triangle.html
    # dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        row_count = len(triangle)
        dp = triangle[-1]
        for row in range(row_count - 2, -1, -1):
            for col in range(row + 1):
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1])
        return dp[0]


t = [
    [2],
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
]
s = Solution()

# print s.minimumTotal(t)

t = [[-1], [2, 3], [1, -1, -3]]
print s.minimumTotal(t)
