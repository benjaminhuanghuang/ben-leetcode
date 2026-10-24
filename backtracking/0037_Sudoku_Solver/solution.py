'''
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
'''


class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.solve(0, board)

    def check(self, x, y, board):
        for i in range(0, 9):
            # check col and row
            if board[x][i] == board[x][y] and i != y or board[i][y] == board[x][y] and i != x:
                return False
        for i in range(0, 3):
            for j in range(0, 3):
                if board[x / 3 * 3 + i][y / 3 * 3 + j] == board[x][y] and x != x / 3 * 3 + i and y != y / 3 * 3 + j:
                    return False
        return True

    def solve(self, cur, board):
        if cur == 81:
            return True

        i, j = cur / 9, cur % 9
        if board[i][j] != '.':
            return self.solve(cur + 1, board)

        for k in range(1, 10):
            a = list(board[i])
            a[j] = str(k)
            board[i] = ''.join(a)
            if self.check(i, j, board) and self.solve(cur + 1, board):
                return True
            a[j] = '.'
            board[i] = ''.join(a)

        return False


input = ["..9748...",
         "7........",
         ".2.1.9...",
         "..7...24.",
         ".64.1.59.",
         ".98...3..",
         "...8.3.2.",
         "........6",
         "...2759.."]

s = Solution()
print s.solveSudoku(input)
