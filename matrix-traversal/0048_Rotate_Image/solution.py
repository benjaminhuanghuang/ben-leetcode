class Solution(object):
    # http://www.tianmaying.com/tutorial/LC48
    # [i, j] -> [j, n-i-1] -> [n-i-1, n-j-1] -> [n-j-1, i] -> [i, j]
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if matrix is None:
            return

        n = len(matrix) - 1
        for layer in xrange(n / 2 + 1):
            # xrange(i, n - i) for there are n is odd
            for offset in xrange(layer, n - layer):
                tmp = matrix[layer][offset]
                matrix[layer][offset] = matrix[n-offset][layer]
                matrix[n-offset][layer] = matrix[n-layer][n-offset]
                matrix[n-layer][n-offset] = matrix[offset][n-layer]
                matrix[offset][n-layer] = tmp
