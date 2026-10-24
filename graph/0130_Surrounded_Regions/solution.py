# coding : utf-8
'''
130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

'''


class Solution(object):
    # https://shenjie1993.gitbooks.io/leetcode-python/content/130%20Surrounded%20Regions.html
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board or len(board) <= 0:
            return

        row_count = len(board)
        col_count = len(board[0])

        # check first and last element in each line
        for i in xrange(row_count):
            self.check(board, i, 0, row_count, col_count)
            if col_count > 1:
                self.check(board, i, col_count - 1, row_count, col_count)

        # check first and last element in each col
        for j in xrange(1, col_count - 1):
            self.check(board, 0, j, row_count, col_count)
            if row_count > 1:
                self.check(board, row_count - 1, j, row_count, col_count)

        for i in xrange(row_count):
            for j in xrange(col_count):
                if board[i][j] == "O":
                    board[i][j] = "X"
                if board[i][j] == "#":
                    board[i][j] = "O"

    # find out all 'O' is NOT surrounded by 'X'
    def check(self, board, i, j, row_count, col_count):
        if i < 0 or i >= row_count or j < 0 or j >= col_count:
            return

        if board[i][j] == 'O':
            board[i][j] = '#'  # the cell adjacent to
            if i > 1:
                self.check(board, i - 1, j, row_count, col_count)
            if i < row_count - 1:
                self.check(board, i + 1, j, row_count, col_count)
            if j > 1:
                self.check(board, i, j - 1, row_count, col_count)
            if j < col_count:
                self.check(board, i, j + 1, row_count, col_count)


board = [
    ['X', 'X', 'X', 'X'],
    ['X', 'O', 'O', 'X'],
    ['X', 'X', 'O', 'X'],
    ['X', 'O', 'X', 'X']
]
expected_board = [
    ['X', 'X', 'X', 'X'],
    ['X', 'X', 'X', 'X'],
    ['X', 'X', 'X', 'X'],
    ['X', 'O', 'X', 'X']
]
