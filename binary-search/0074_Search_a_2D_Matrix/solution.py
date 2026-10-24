'''
74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

'''


class Solution(object):
    # Passed at first try
    def searchMatrix_1(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not matrix[0]:
            return False

        row = len(matrix)
        col = len(matrix[0])

        for i in xrange(row):
            if matrix[i][-1] < target:
                continue
            elif matrix[i][-1] > target:
                for j in xrange(col - 1, -1, -1):
                    if matrix[i][j] == target:
                        return True
            else:
                return True
        return False

    def searchMatrix_better(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if matrix is None:
            return False

        i = 0
        j = len(matrix[0]) - 1

        while i < len(matrix) and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:  # matrix[i][-1] < target
                i += 1
        return False


s = Solution()

print s.searchMatrix_better([[1, 3]], 1)
