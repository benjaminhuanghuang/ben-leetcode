'''
36. Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.


'''


class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        if len(board) != 9 or len(board[0]) != 9:
            return False

        for i in range(9):
            map = [0] * 10
            for j in range(9):
                if board[i][j] == '.':
                    continue
                if board[i][j] < '0' or board[i][j] > '9':
                    return False
                num = ord(board[i][j]) - ord('0')
                if map[num] == 1:
                    return False
                map[num] = 1

        for j in range(9):
            map = [0] * 10
            for i in range(9):
                if board[i][j] == '.':
                    continue
                num = ord(board[i][j]) - ord('0')
                if map[num] == 1:
                    return False
                map[num] = 1

        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                map = [0] * 10
                for k in range(i, i + 3):
                    for l in range(j, j + 3):
                        if board[k][l] == '.':
                            continue
                        num = ord(board[k][l]) - ord('0')
                        if map[num] == 1:
                            return False
                        map[num] = 1
        return True


input = [".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........",
         "9........"]
input2 = ["....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...", ".2.9.....",
          "..4......"]
s = Solution()
print s.isValidSudoku(input)
print s.isValidSudoku(input2)
