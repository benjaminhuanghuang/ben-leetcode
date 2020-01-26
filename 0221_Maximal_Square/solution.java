package cn.huang.leetcode;
/*
221. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4


 */


public class LC_0221_MaximalSquare {
    /*
        dynamic programing.  以当前点(x,y) = '1' 为右下角的最大正方形的边长f(x,y) = min( f(x-1,y), f(x,y-1), f(x-1,y-1)) + 1.

        递推公式已建立, dp就自然而然了.

        */
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return 0;

        int n = matrix.length;
        int m = matrix[0].length;

        int[][] d = new int[n][m];
        int max = 0;

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1') {
                d[i][0] = 1;
                max = 1;
            }
        }

        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == '1') {
                d[0][j] = 1;
                max = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0')
                    d[i][j] = 0;
                else {
                    d[i][j] = Math.min(Math.min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
                    max = Math.max(max, d[i][j]);
                }
            }
        }
        return max * max;
    }

    /*
    DP，新建一个m+1, n+1大小的dp矩阵，dp矩阵中存的数字为构成一个squre的边长大小
    然后从（1，1）点开始填数，原矩阵从（0，0）开始遍历，
    当原矩阵中的数为1时，我们更新dp矩阵的数字为左上角的三个数字的最小值+1，，
    每次更新dp矩阵的某个数值时都update一下最长length，填完dp矩阵后输出边长的平方即可。
     */
    public int maximalSquare2(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return 0;
        int m = matrix.length, n = matrix[0].length;
        int length = 0;

        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    if (dp[i][j] > length) {
                        length = dp[i][j];
                    }
                }
            }
        }
        return length * length;
    }
}
