class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        for i in range(numRows):
            curr_row = [1] * (i + 1)
            if i > 1:
                for x in range(i - 1):
                    curr_row[x + 1] = result[i - 1][x] + result[i - 1][x + 1]
            print curr_row
            result.append(curr_row)
        return result


class Solution_my(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        for row in range(numRows):
            values = []
            for col in range(row + 1):
                if col == 0 or col == row:
                    values.append(1)
                else:
                    values.append(res[row - 1][col - 1] + res[row - 1][col])
            res.append(values)
        return res


s = Solution_my()

res = s.generate(5)
print res
