package cn.huang.leetcode;

/*
529. Minesweeper
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

    If a mine ('M') is revealed, then the game is over - change it to 'X'.
    If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
    If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
    Return the board when no more squares will be revealed.



Example 1:

Input:

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:

Input:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:



Note:

    The range of the input matrix's height and width is [1,50].
    The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
    The input board won't be a stage when game is over (some mines have been revealed).
    For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.


 */
public class LC_0529_Minesweeper {
    /*
    https://blog.csdn.net/qq_33797928/article/details/80251974

     */
    public char[][] updateBoard(char[][] board, int[] click) {
        if (board.length <= 0 || board[0].length <= 0) {
            return board;
        }
        char[][] tmpBoard = new char[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                tmpBoard[i][j] = board[i][j];
            }
        }
        changeBoard(tmpBoard, click);
        return tmpBoard;
    }

    private void changeBoard(char[][] board, int[] click) {
        int x = click[0];
        int y = click[1];
        if (x < 0 || y < 0 || x >= board.length || y >= board[0].length) {
            return;
        }
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] != 'E') {
            return;
        }
        int mineNumber = (x - 1 >= 0 ? (board[x - 1][y] == 'M' ? 1 : 0) : 0)
                + (x - 1 >= 0 && y - 1 >= 0 ? (board[x - 1][y - 1] == 'M' ? 1
                : 0) : 0)
                + (x - 1 >= 0 && y + 1 < board[0].length ? (board[x - 1][y + 1] == 'M' ? 1
                : 0)
                : 0)
                + (y - 1 >= 0 ? (board[x][y - 1] == 'M' ? 1 : 0) : 0)
                + (y + 1 < board[0].length ? (board[x][y + 1] == 'M' ? 1 : 0)
                : 0)
                + (x + 1 < board.length ? (board[x + 1][y] == 'M' ? 1 : 0) : 0)
                + (x + 1 < board.length && y - 1 >= 0 ? (board[x + 1][y - 1] == 'M' ? 1
                : 0)
                : 0)
                + (x + 1 < board.length && y + 1 < board[0].length ? (board[x + 1][y + 1] == 'M' ? 1
                : 0)
                : 0);
        if (mineNumber == 0) {
            board[x][y] = 'B';
            changeBoard(board, new int[]{x - 1, y});
            changeBoard(board, new int[]{x - 1, y - 1});
            changeBoard(board, new int[]{x - 1, y + 1});
            changeBoard(board, new int[]{x, y - 1});
            changeBoard(board, new int[]{x, y + 1});
            changeBoard(board, new int[]{x + 1, y - 1});
            changeBoard(board, new int[]{x + 1, y});
            changeBoard(board, new int[]{x + 1, y + 1});
        } else {
            board[x][y] = (char) (mineNumber + '0');
        }
    }
}
