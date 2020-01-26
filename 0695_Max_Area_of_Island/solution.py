'''
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are
surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
'''


class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        visited = [[False for c in xrange(cols)] for r in xrange(rows)]

        maxArea = 0
        for r in xrange(rows):
            for c in xrange(cols):
                if visited[r][c]:  # visited
                    continue

                area = self.findArea( r, c, grid, visited)
                maxArea = max(area, maxArea)

        return maxArea

    def findArea(self, r, c, grid, visited):
        print r, c,len(grid) ,len(grid[0])
        if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or visited[r][c] or grid[r][c] == 0:
            return 0
        area = 1
        visited[r][c] = True
        area += self.findArea(r - 1, c, grid, visited)
        area += self.findArea(r + 1, c, grid, visited)
        area += self.findArea(r, c - 1, grid, visited)
        area += self.findArea(r, c + 1, grid, visited)
        return area


s = Solution()
print s.maxAreaOfIsland([[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]])