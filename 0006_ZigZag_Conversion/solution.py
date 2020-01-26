'''
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

'''


class Solution(object):

    # https://www.youtube.com/watch?v=FyBqMBNj1p0
    # for row = 0 or row  = numRows -1 , there are two numbers and the gap is 2 * (numRows -1)
    # for 0 < row < numRows, there are 3 numbers and the gap is 2 * (numRows -1) - 2 * row and 2*row
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1:
            return s

        # key point
        gap_in_row = 2 * (numRows - 1)
        result = ""
        n = len(s)
        for row in xrange(numRows):
            for col in xrange(row, n, gap_in_row):
                result += s[col]
                if row > 0 and row < numRows - 1 and col + 2 * (numRows - 1 - row) < n:
                    result += s[col + 2 * (numRows - 1 - row)]

        return result


    # http://bookshadow.com/weblog/2015/08/12/leetcode-zigzag-conversion/
    def convert_1(self, s, numRows):
        if numRows == 1 or numRows >= len(s):
            return s

        zigzag = [[] for x in range(numRows)]
        row, step = 0, 1
        for char in s:
            zigzag[row] += char,
            if row == 0:
                step = 1
            elif row == numRows - 1:
                step = -1
            row += step
        return ''.join(reduce(operator.add, zigzag))


s = Solution()

print s.convert("ABC", 3)
