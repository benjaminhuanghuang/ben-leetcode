class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n == 0:
            return []
        #  Note! [[0] * n] * n has same reference!
        # matrix = [[0] * n] * n

        matrix = [[0 for i in range(n)] for j in range(n)]
        up = 0
        down = n - 1
        left = 0
        right = n - 1
        direct = 0
        current = 0

        while True:
            if direct == 0:  # left to right
                for i in range(left, right + 1):
                    current += 1
                    matrix[up][i] = current
                up += 1
            if direct == 1:  # up to down
                for i in range(up, down + 1):
                    current += 1
                    matrix[i][right] = current
                right -= 1
            if direct == 2:  # right to left
                for i in range(right, left - 1, -1):
                    current += 1
                    matrix[down][i] = current
                down -= 1
            if direct == 3:  # down to up
                for i in range(down, up - 1, -1):
                    current += 1
                    matrix[i][left] = current
                left += 1
            if current == n * n:
                return matrix
            direct = (direct + 1) % 4


s = Solution()
print s.generateMatrix(2)
