package cn.huang.leetcode;

/*
794. Valid Tic-Tac-Toe State

A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board
position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

    Players take turns placing characters into empty squares (" ").
    The first player always places "X" characters, while the second player always places "O" characters.
    "X" and "O" characters are always placed into empty squares, never filled ones.
    The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.

Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true

Note:

    board is a length-3 array of strings, where each string board[i] has length 3.
    Each board[i][j] is a character in the set {" ", "X", "O"}.


 */
public class LC_0794_ValidTicTacToeState {
    public boolean validTicTacToe(String[] board) {
        // filter abnormal cases
        if (board == null || board.length == 0) {
            return false;
        }

        char[][] boards = new char[3][3];
        int xNum = 0;
        int oNum = 0;
        int xOk = 0;
        int oOk = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                boards[i][j] = board[i].charAt(j);
                if (boards[i][j] == 'X') {
                    xNum++;
                } else if (boards[i][j] == 'O') {
                    oNum++;
                }
            }
        }
        if (oNum > xNum || xNum - oNum > 1) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            if (boards[i][0] == boards[i][1] && boards[i][1] == boards[i][2] && boards[i][0] != ' ') {
                if (boards[i][0] == 'X') xOk += 1;
                else oOk += 1;
            }
            if (boards[0][i] == boards[1][i] && boards[1][i] == boards[2][i] && boards[0][i] != ' ') {
                if (boards[0][i] == 'X') xOk += 1;
                else oOk += 1;
            }
        }
        if (boards[0][0] == boards[1][1] && boards[1][1] == boards[2][2] && boards[0][0] != ' ') {
            if (boards[0][0] == 'X') xOk += 1;
            else oOk += 1;
        }
        if (boards[0][2] == boards[1][1] && boards[1][1] == boards[2][0] && boards[0][2] != ' ') {
            if (boards[0][2] == 'X') xOk += 1;
            else oOk += 1;
        }
        if (xOk > 0 && oOk > 0) {
            return false;
        } else if (xOk > 0 && xNum <= oNum) {
            return false;
        } else if (oOk > 0 && xNum > oNum) {
            return false;
        }
        return true;
    }
}
