package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


 */
public class LC_0051_NQueens {
    /*
        Assume there are n queens in the board in 0 – n-1 rows.
        then in nth row, put a queen in each cell, check if it a valid solution.
        if it is go ahead and do the n + 1 queens in the board in 0 – n rows.
        if not, back trace and remove that queen and test another cell.
    */
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<List<String>>();
        int[] queenList = new int[n]; //第i个位置存放的数表示row行的queen所在的列
        placeQueen(queenList, 0, n, res);//在第0行放Q
        return res;
    }

    private void placeQueen(int[] queenList, int row, int n, List<List<String>> res) {
        //如果已经填满，就生成结果
        if (row == n) {
            ArrayList<String> list = new ArrayList<String>();
            for (int i = 0; i < n; i++) {
                String str = "";
                for (int col = 0; col < n; col++) {
                    if (queenList[i] == col) {
                        str += "Q";
                    } else {
                        str += ".";
                    }
                }
                list.add(str);
            }
            res.add(list);
        }
        for (int col = 0; col < n; col++) {//循环每一列
            if (isValid(queenList, row, col)) { //如果在该列放入Q不冲突的话
                queenList[row] = col;
                placeQueen(queenList, row + 1, n, res);
            }
        }
    }

    private boolean isValid(int[] queenList, int row, int col) {
        for (int r = 0; r < row; r++) {
            int c = queenList[r];
            if (c == col) { //和新加入的Q处于同一列
                return false;
            }
            if (c - r == col - row) { //在新加入的Q的右对角线上
                return false;
            }
            if (c + r == col + row) { //在新加入的Q的左对角线上
                return false;
            }
        }
        return true;
    }
}
