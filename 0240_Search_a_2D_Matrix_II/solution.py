'''
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
'''


class Solution(object):
    # O (m + n)
    def searchMatrix_niave(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # From bottom-right corner, if matrix[x][y] > target, y--
        col = len(matrix[0]) - 1
        for row in range(len(matrix)):
            while col >= 0 and matrix[row][col] > target:
                col -= 1
            if matrix[row][col] == target:
                return True
        return False

    # bin search O(m*logN)
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False

        m = len(matrix)
        n = len(matrix[0])

        row, col = 0, n - 1

        while row < m and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] < target:
                row += 1
            else:
                col -= 1
        return False
