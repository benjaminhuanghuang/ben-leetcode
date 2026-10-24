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
