package cn.huang.leetcode;

/*
79. Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.


 */

/*
https://www.youtube.com/watch?v=Hcj1qVBD3YM
https://www.youtube.com/watch?v=oUeGFKZvoo4
Time O(m*n*4^l)
Space(m*n + l)
 */
public class LC_0079_WordSearch {
    public boolean exist(char[][] board, String word) {
        int rows = board.length;
        int cols = board[0].length;

        boolean[][] visited = new boolean[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (helper(board, i, j, word, 0, visited))
                        return true;
                }
            }
        }

        return false;
    }

    private boolean helper(char[][] board, int i, int j, String word, int index, boolean[][] visited) {
        if (i < 0 || i >= board.length ||
                j < 0 || j >= board[0].length ||
                board[i][j] != word.charAt(index) || visited[i][j])
            return false;
        if (index == word.length() - 1)
            return true;

        visited[i][j] = true;

        if (helper(board, i - 1, j, word, index + 1, visited)) return true;
        if (helper(board, i + 1, j, word, index + 1, visited)) return true;
        if (helper(board, i, j - 1, word, index + 1, visited)) return true;
        if (helper(board, i, j + 1, word, index + 1, visited)) return true;

        visited[i][j] = false;

        return false;
    }
}
