package cn.huang.leetcode;

/*
782. Transform to Chessboard

An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.

Examples:
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation:
One potential sequence of moves is shown below, from left to right:

0110     1010     1010
0110 --> 1010 --> 0101
1001     0101     1010
1001     0101     0101

The first move swaps the first and second column.
The second move swaps the second and third row.


Input: board = [[0, 1], [1, 0]]
Output: 0
Explanation:
Also note that the board with 0 in the top left corner,
01
10

is also a valid chessboard.

Input: board = [[1, 0], [1, 0]]
Output: -1
Explanation:
No matter what sequence of moves you make, you cannot end with a valid chessboard.

Note:

    board will have the same number of rows and columns, a number in the range [2, 30].
    board[i][j] will be only 0s or 1s.


 */
public class LC_0782_TransformtoChessboard {
    /*
    https://leetcode.com/problems/transform-to-chessboard/discuss/132113/Java-Clear-Code-with-Detailed-Explanations
    */
    public int movesToChessboard(int[][] board) {
        int N = board.length, colToMove = 0, rowToMove = 0, rowOneCnt = 0, colOneCnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (((board[0][0] ^ board[i][0]) ^ (board[i][j] ^ board[0][j])) == 1) {
                    return -1;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            rowOneCnt += board[0][i];
            colOneCnt += board[i][0];
            if (board[i][0] == i % 2) {
                rowToMove++;
            }
            if (board[0][i] == i % 2) {
                colToMove++;
            }
        }
        if (rowOneCnt < N / 2 || rowOneCnt > (N + 1) / 2) {
            return -1;
        }
        if (colOneCnt < N / 2 || colOneCnt > (N + 1) / 2) {
            return -1;
        }
        if (N % 2 == 1) {
            // we cannot make it when ..ToMove is odd
            if (colToMove % 2 == 1) {
                colToMove = N - colToMove;
            }
            if (rowToMove % 2 == 1) {
                rowToMove = N - rowToMove;
            }
        } else {
            colToMove = Math.min(colToMove, N - colToMove);
            rowToMove = Math.min(rowToMove, N - rowToMove);
        }
        return (colToMove + rowToMove) / 2;
    }
}
