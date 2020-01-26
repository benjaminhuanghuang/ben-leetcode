package cn.huang.leetcode;
/*
348. Design Tic-Tac-Toe

Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

    A move is guaranteed to be valid and is placed on an empty block.
    Once a winning condition is reached, no more moves is allowed.
    A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Example:

Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

Follow up:
Could you do better than O(n2) per move() operation?

Hint:

    Could you trade extra space such that move() operation can be done in O(1)?
    You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
 */


/*
类似八皇后问题，记录各行各列以及对角线的落子情况。

 */
public class LC_0348_DesignTicTacToe {
    public class TicTacToe {
        private int[][] rows;
        private int[][] cols;
        private int[] diag = new int[2]; //diagonal
        private int[] adiag = new int[2]; //anti_diagonal
        private int size;

        /**
         * Initialize your data structure here.
         */
        public TicTacToe(int n) {
            size = n;
            rows = new int[n][2];
            cols = new int[n][2];
        }

        /**
         * Player {player} makes a move at ({row}, {col}).
         *
         * @param row    The row of the board.
         * @param col    The column of the board.
         * @param player The player, can be either 1 or 2.
         * @return The current winning condition, can be either:
         * 0: No one wins.
         * 1: Player 1 wins.
         * 2: Player 2 wins.
         */
        public int move(int row, int col, int player) {
            rows[row][player - 1]++;
            if (rows[row][player - 1] == size)
                return player;
            cols[col][player - 1]++;
            if (cols[col][player - 1] == size)
                return player;

            if (row == col) {
                diag[player - 1]++;
                if (diag[player - 1] == size)
                    return player;
            }
            if (row + col == size - 1) {
                adiag[player - 1]++;
                if (adiag[player - 1] == size)
                    return player;
            }
            return 0;
        }
    }
}
