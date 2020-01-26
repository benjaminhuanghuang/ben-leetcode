'''
463. Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water,
and there is exactly "one" island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100.

Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

'''


class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        perimeter = 0;
        rows = len(grid)
        cols = len(grid[0])

        for row in range(rows):
            for col in range(cols):
                if (grid[row][col] == 1):
                    if (row == 0 or grid[row - 1][col] == 0):  # top adjacent to water or top border
                        perimeter += 1
                    if (row == rows - 1 or grid[row + 1][col] == 0):  # bottom adjacent to water or bottom border
                        perimeter += 1
                    if (col == 0 or grid[row][col - 1] == 0):  # left
                        perimeter += 1
                    if (col == cols - 1 or grid[row][col + 1] == 0):  #right
                        perimeter += 1

        return perimeter
