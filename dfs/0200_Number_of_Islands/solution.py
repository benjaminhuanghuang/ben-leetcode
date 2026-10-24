'''
200. Number of Islands


Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3


Reference:
    http://www.tangjikai.com/algorithms/leetcode-200-number-of-islands
'''


class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        visit = [[False for i in range(n)] for j in range(m)]

        def check(x, y):
            if x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == '1' and visit[x][y] == False:
                return True

        def dfs(x, y):
            nbrow = [1, 0, -1, 0]
            nbcol = [0, 1, 0, -1]
            for k in range(4):
                newx = x + nbrow[k]
                newy = y + nbcol[k]
                if check(newx, newy):
                    visit[newx][newy] = True
                    dfs(newx, newy)

        count = 0
        for row in range(m):
            for col in range(n):
                if check(row, col):
                    visit[row][col] = True
                    dfs(row, col)
                    count += 1
        return count

    def numIslands_1(self, grid):
        m = len(grid)

        if m == 0:
            return 0
        n = len(grid[0])
        count = 0
        for row in range(m):
            for col in range(n):
                if grid[row][col] == '1':
                    self.search(grid, row, col)
                    count += 1
        return count

    def search(self, grid, x, y):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] != '1':
            return
        grid[x][y] = "0"
        self.search(grid, x - 1, y)
        self.search(grid, x + 1, y)
        self.search(grid, x, y - 1)
        self.search(grid, x, y + 1)
