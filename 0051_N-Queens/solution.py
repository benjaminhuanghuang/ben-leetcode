'''
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate
a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

http://www.jianshu.com/p/8f3b8df612ae
http://www.jiuzhang.com/solutions/n-queens/
'''


class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        result = []
        if n <= 0:
            return result

        poses = []  # queen's position in each row
        self.search(n, poses, result)
        return result

    def search(self, n, poses, result):
        if len(poses) == n:
            result.append(self.drawBoard(poses))

        for pos in range(n):
            if not self.isValid(poses, pos):
                continue
            self.search(n, poses + [pos], result)  # should pass in a new list

    def isValid(self, poses, pos):
        next_row = len(poses)
        next_col = pos
        for row in range(len(poses)):
            if pos == poses[row]:  # tow Q in same col. poses[row] is the col of Q in row
                return False
            if next_row - row == next_col - poses[row]:  # left_top to right_bottom
                return False
            if poses[row] - next_col == next_row - row:  # right_top to left_bottom
                return False
        return True

    def drawBoard(self, poses):
        board = []
        for row in range(len(poses)):
            line = ""
            for col in range(len(poses)):
                if col == poses[row]:
                    line += "Q"
                else:
                    line += "."
            board.append(line)
        return board


s = Solution()
print s.solveNQueens(5)
