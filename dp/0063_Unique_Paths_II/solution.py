'''
63. Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

'''


class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        rows = len(obstacleGrid)
        cols = len(obstacleGrid[0])

        if obstacleGrid[0][0] == 1:
            return 0
        elif rows == 1 and cols == 1:
            return 1

        paths = [[0 for i in range(cols)] for j in range(rows)]
        paths[0][0] = 1

        for i in xrange(1, rows):
            if obstacleGrid[i][0] != 1:
                paths[i][0] = paths[i - 1][0]

        for j in range(1, cols):
            if obstacleGrid[0][j] != 1:
                paths[0][j] = paths[0][j - 1]

        for i in range(1, rows):
            for j in range(1, cols):
                if obstacleGrid[i][j] != 1:
                    paths[i][j] = paths[i][j - 1] + paths[i - 1][j]

        return paths[-1][-1]

    def uniquePathsWithObstacles_9(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        mp = obstacleGrid
        for i in range(len(mp)):
            for j in range(len(mp[i])):
                if i == 0 and j == 0:
                    mp[i][j] = 1 - mp[i][j]  # if mp[i][j] == 1, path =0
                elif i == 0:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i][j - 1]
                elif j == 0:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i - 1][j]
                else:
                    if mp[i][j] == 1:
                        mp[i][j] = 0
                    else:
                        mp[i][j] = mp[i - 1][j] + mp[i][j - 1]
        return mp[-1][-1]

    def uniquePathsWithObstacles_2(self, obstacleGrid):
        rows = len(obstacleGrid)
        cols = len(obstacleGrid[0])

        if obstacleGrid[0][0] == 1:
            return 0
        elif rows == 1 and cols == 1:
            return 1

        paths = [[] for i in range(rows)]

        for i in range(rows):
            if obstacleGrid[i][0] == 1:
                while (i < rows):
                    paths[i].append(0)
                    i += 1
                break
            else:
                paths[i].append(1)

        for j in range(1, cols):
            if obstacleGrid[0][j] == 1:
                while (j < cols):
                    paths[0].append(0)
                    j += 1
                break
            else:
                paths[0].append(1)

        for i in range(1, rows):
            for j in range(1, cols):
                if obstacleGrid[i][j] == 1:
                    paths[i].append(0)
                else:
                    paths[i].append(paths[i][j - 1] + paths[i - 1][j])

        return paths[-1][-1]

    def uniquePathsWithObstacles_3(self, obstacleGrid):
        rows = len(obstacleGrid)
        cols = len(obstacleGrid[0])

        res = [[0 for i in range(cols)] for j in range(rows)]
        for i in range(rows):
            if obstacleGrid[i][0] == 0:
                res[i][0] = 1
            else:
                res[i][0] == 0
                break
        for i in range(cols):
            if obstacleGrid[0][i] == 0:
                res[0][i] = 1
            else:
                res[0][i] = 0
                break

        for i in range(1, rows):
            for j in range(1, cols):
                if obstacleGrid[i][j] == 1:
                    res[i][j] = 0
                else:
                    res[i][j] = res[i - 1][j] + res[i][j - 1]
        return res[rows - 1][cols - 1]


grid = [
    [0, 1, 0],
    [0, 1, 0],
    [0, 1, 0]
]

s = Solution()
res = s.uniquePathsWithObstacles(grid)

print res
