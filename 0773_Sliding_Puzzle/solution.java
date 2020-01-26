package cn.huang.leetcode;

import java.util.*;

/*
773. Sliding Puzzle

On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is
impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

Input: board = [[3,2,4],[1,5,0]]
Output: 14

Note:

    board will be a 2 x 3 array as described above.
    board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].


 */
public class LC_0773_SlidingPuzzle {
    int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    Map<Integer, Integer> map = new HashMap<>();
    int min_move = Integer.MAX_VALUE;
    public int slidingPuzzle(int[][] board) {
        map.put(123450, 0);
        int[] zero = new int[2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    zero[0] = i;
                    zero[1] = j;
                    break;
                }
            }
        }
        helper(board, zero[0], zero[1], 0);
        return min_move == Integer.MAX_VALUE ? -1 : min_move;
    }
    private void helper(int[][] board, int x, int y, int move) {
        if (move > min_move) return;
        int code = encode(board);
        if (code == 123450) {
            min_move = move;
            return;
        }
        if (map.containsKey(code)) {
            if (move > map.get(code)) return;
        }
        map.put(code, move);
        for (int[] dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
                swap(board, x, y, nx, ny);
                helper(board, nx, ny, move + 1);
                swap(board, nx, ny, x, y);
            }
        }
    }
    private void swap (int[][] board, int i, int j, int ii, int jj) {
        int temp = board[i][j];
        board[i][j] = board[ii][jj];
        board[ii][jj] = temp;
    }
    private int encode(int[][] board) {
        int code = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                code *= 10;
                code += board[i][j];
            }
        }
        return code;
    }

}
