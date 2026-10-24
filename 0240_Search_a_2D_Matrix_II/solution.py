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
