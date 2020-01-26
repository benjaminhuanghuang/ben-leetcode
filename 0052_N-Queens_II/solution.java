package cn.huang.leetcode;

/*
52. N-Queens II

Now, instead outputting board configurations, return the total number of distinct solutions.

 */

/*
https://www.youtube.com/watch?v=0uZg0ZkUgP8

 */
public class LC_0052_NQueens_II {
    int result = 0;

    public int totalNQueens(int n) {
        int[] pos = new int[n];
        putQueen(pos, n, 0);
        return result;
    }

    public void putQueen(int[] queenList, int n, int row) {
        if (row == n) {
            result++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(queenList, row, col)) {//判断合法
                queenList[row] = col;//将皇后放在第row行，第i列
                putQueen(queenList, n, row + 1);//寻找下一行
                // queenList[row] = 0;// 由于queenList[row]只有一个值，此处无需回溯
            }
        }
    }

    boolean isValid(int[] queenList, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queenList[i] == col    //same column, queenList[i] is the col of the Queen at row[i]
                    || queenList[i] + i == col + row  // anti-diagonal
                    || queenList[i] - i == col - row) // diagonal
                return false;
        }
        return true;
    }
}
