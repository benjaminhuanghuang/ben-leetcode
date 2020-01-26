package cn.huang.leetcode;

/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.
 */
public class LC_0037_SudokuSolver {
    public void solveSudoku(char[][] board) {
        slove(0, board);
    }

    private boolean slove(int curr, char[][] board) {
        if (curr == 81)
            return true;
        int row = curr / 9;
        int col = curr % 9;
        if (board[row][col] != '.')
            return this.slove(curr + 1, board);

        for (int k = 1; k <= 9; k++)  // try num 1 to 9 at borad[row][col]
        {
            board[row][col] = (char) (k + '0');
            if (this.isValid(board, row, col) && this.slove(curr + 1, board))
                return true;
            board[row][col] = '.';  // back track, recover board[row][col] and try next one
        }

        return false;
    }


    // Check the char at board[x, y] is valid or not.
    private boolean isValid(char[][] board, int row, int col) {
        int size = board.length;

        // Check the cross board[x, i], board[i, y]
        for (int i = 0; i < 9; i++) {
            // check column and row
            if ((board[row][i] == board[row][col] && i != col) ||
                    (board[i][col] == board[row][col] && i != row)) {
                return false;
            }
        }
        // Check the square contains [x, y]
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int r = row / 3 * 3 + i;
                int c = col / 3 * 3 + j;
                if (board[r][c] == board[row][col] && row != r && col != c)
                    return false;
            }
        }
        return true;
    }
}
