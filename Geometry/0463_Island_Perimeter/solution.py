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
