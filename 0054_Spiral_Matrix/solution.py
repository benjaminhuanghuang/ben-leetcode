'''
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
'''


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        if matrix is None or len(matrix) <= 0:
            return []

        up = 0
        left = 0
        down = len(matrix) - 1
        right = len(matrix[0]) - 1

        direct = 0  # 0: right   1: down  2: left  3: up
        res = []
        while up <= down and left <= right:
            if direct == 0:
                for i in range(left, right + 1):
                    res.append(matrix[up][i])
                up += 1
            if direct == 1:
                for i in range(up, down + 1):
                    res.append(matrix[i][right])
                right -= 1
            if direct == 2:
                for i in range(right, left - 1, -1):
                    res.append(matrix[down][i])
                down -= 1
            if direct == 3:
                for i in range(down, up - 1, -1):
                    res.append(matrix[i][left])
                left += 1
            direct = (direct + 1) % 4
        return res
