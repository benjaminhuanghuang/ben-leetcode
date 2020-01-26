'''
119. Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
'''


class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex <= 0:
            return [1]
        result = []
        for i in range(rowIndex + 1):
            # curr_row = []
            # for j in range(i + 1):
            #     curr_row.append(1)
            curr_row = [1] * (i + 1)
            if i > 1:
                for x in range(i - 1):
                    curr_row[x + 1] = result[i - 1][x] + result[i - 1][x + 1]
            result.append(curr_row)
        return result[-1]
