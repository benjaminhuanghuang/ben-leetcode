'''
52. N-Queens II

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
'''


class Solution(object):
    # each row can only have one queen, so use [-1]*n represent the board
    # use result = [0] instead of result = 0 because array ban be modified in sub function
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = [0]
        board = [-1] * n
        self.search(0, board, result)
        return result[0]

    def is_valid(self, board, row):
        for i in range(row):
            if board[i] == board[row]:
                return False
            if abs(board[i] - board[row]) == row - i:
                return False
        return True

    def search(self, row, board, result):
        if row == len(board):
            result[0] += 1
        else:
            for col in range(len(board)):
                board[row] = col
                if self.is_valid(board, row):
                    self.search(row + 1, board, result)



class Solution_9:
    """
    Calculate the total number of distinct N-Queen solutions
    @param n: The number of queens.
    @return: The total number of distinct solutions.
    """
    total = 0
    n = 0

    def attack(self, row, col):
        for c, r in self.cols.iteritems():
            if c - r == col - row or c + r == col + row:
                return True
        return False

    def search(self, row):
        if row == self.n:
            self.total += 1
            return
        for col in range(self.n):
            if col in self.cols:
                continue
            if self.attack(row, col):
                continue
            self.cols[col] = row
            self.search(row + 1)
            del self.cols[col]

    def totalNQueens(self, n):
        self.n = n
        self.cols = {}
        self.search(0)
        return self.total


s = Solution()
print s.totalNQueens(8)
