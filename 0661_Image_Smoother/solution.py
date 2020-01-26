'''
661. Image Smoother

'''


class Solution(object):
    def imageSmoother_TLE(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        size = len(M)
        offsets = [[-1, -1], [-1, 0], [-1, 1],
                   [0, -1], [0, 1],
                   [1, -1], [1, 0], [1, 1]]
        res = [[0 for _ in range(size)] for _ in range(size)]  # TLE
        for row in range(len(M)):
            for col in range(len(M[0])):
                summary = 0
                count = 0
                for offset in offsets:
                    if row + offset[0] >= 0 and row + offset[0] < size and \
                                            col + offset[1] >= 0 and col + offset[1] < size:
                        count += 1
                        summary += M[row][col]
                res[row][col] = summary / count
        return res

    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        dx, dy = [-1, 0, 1], [-1, 0, 1]
        w, h = len(M), len(M[0])
        N = []
        for x in range(w):
            row = []
            for y in range(h):
                nbs = [M[x + i][y + j] for i in dx for j in dy \
                       if 0 <= x + i < w and 0 <= y + j < h]
                row.append(sum(nbs) / len(nbs))
            N.append(row)
        return N

M = [[1,1,1],[1,0,1],[1,1,1]]

s = Solution()
print s.imageSmoother(M)