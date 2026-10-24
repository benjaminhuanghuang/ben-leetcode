'''
73. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
'''


class Solution(object):
    def setZeroes_my(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if not matrix or len(matrix) == 0:
            return

        rownum = len(matrix)
        colnum = len(matrix[0])

        row = [False for i in range(rownum)]
        col = [False for i in range(colnum)]

        for i in range(rownum):
            for j in range(colnum):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True

        for i in range(rownum):
            for j in range(colnum):
                if row[i] or col[j]:
                    matrix[i][j] = 0
