package cn.huang.leetcode;

/*
999. Available Captures for Rook

On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.
These are given as characters 'R', '.', 'B', and 'p' respectively.

Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.



Example 1:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation:
In this example the rook is able to capture all the pawns.
Example 2:



Input: [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 0
Explanation:
Bishops are blocking the rook to capture any pawn.
Example 3:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation:
The rook can capture the pawns at positions b5, d6 and f5.


Note:

board.length == board[i].length == 8
board[i][j] is either 'R', '.', 'B', or 'p'
There is exactly one cell with board[i][j] == 'R'
 */
public class LC_0999_AvailableCapturesforRook {
    public int numRookCaptures_huahua(char[][] board) {
        if (board == null || board.length == 0)
            return 0;

        int row = -1;
        int col = -1;
        int N = board.length;

        int ans = 0;
        int[] dirs = new int[]{1, 0, -1, 0, 1};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'R') {
                    for (int d = 0; d < 4; ++d) {
                        ans += check(board, N, j, i, dirs[d], dirs[d + 1]);
                    }
                }
            }
        }
        return ans;
    }

    private int check(char[][] board, int N, int x, int y, int dx, int dy) {
        x += dx;
        y += dy;
        while (x >= 0 && x < N && y >= 0 && y < N) {
            if(board[y][x] == 'p')
                return 1;
            if(board[y][x] != '.')
                break;
            x += dx;
            y += dy;
        }
        return 0;
    }
    /*
        题意理解有误！
     */
    public int numRookCaptures_my(char[][] board) {
        if (board == null || board.length == 0)
            return 0;

        int row = -1;
        int col = -1;
        int N = board.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        if (row == -1 || col == -1)
            return 0;
        int res = 0;
        for (int i = row - 1; i >= 0; i--) {
            if (Character.isLowerCase(board[i][col])) {
                res++;
                break;
            }
            if (Character.isUpperCase(board[i][col]))
                break;
        }

        for (int i = row + 1; i < N; i++) {
            if (Character.isLowerCase(board[i][col])) {
                res++;
                break;
            }
            if (Character.isUpperCase(board[i][col])) {
                break;
            }
        }


        for (int i = col - 1; i >= 0; i--) {
            if (Character.isLowerCase(board[row][i])) {
                res++;
                break;
            }
            if (Character.isUpperCase(board[row][i])) {
                break;
            }
        }

        for (int i = col + 1; i < N; i++) {
            if (Character.isLowerCase(board[row][i])) {
                res++;
                break;
            }
            if (Character.isUpperCase(board[row][i])) {
                break;
            }

        }

        return res;
    }
}
