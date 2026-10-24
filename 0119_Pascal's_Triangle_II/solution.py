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
