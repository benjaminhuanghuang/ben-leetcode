package cn.huang.leetcode;

/*
931. Minimum Falling Path Sum
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.
The next row's choice must be in a column that is different from the previous row's column by at most one.

 Leetcode 120：三角形最小路径和

 */
public class LC_0931_MinimumFallingPathSum {
    /*
    | 1 | 2 | 3 |
    | 4 | 5 | 6 |
    | 7 | 8 | 9 |

    (1,0)有dp[1][0] = 4 + min(1,2)
    (1,1)有dp[1][1] = 5 + min(1,2,3)
    (1,2)有dp[1][2] = 6 + min(2,3)


    求最小值， 这个是一个经典又相对简单的动态规划(dynamic programming)题目。
    每一个位置的最小值只取决于前面一行相邻的三个位置，所以，常规的递推公式如下：
    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + A[i][j]
    然后对边界条件处理一下就好

     */
    public int minFallingPathSum(int[][] A) {
        int[][] dpmin = new int[A.length][A[0].length];

        for (int i = 0; i < A.length; ++i) {
            for (int j = 0; j < A[0].length; ++j) {
                if (i == 0) {
                    dpmin[i][j] = A[i][j];
                } else {
                    if (j == 0) {
                        dpmin[i][j] = Math.min(dpmin[i - 1][j], dpmin[i - 1][j + 1]) + A[i][j];
                    } else if (j == A[0].length - 1) {
                        dpmin[i][j] = Math.min(dpmin[i - 1][j - 1], dpmin[i - 1][j]) + A[i][j];
                    } else {
                        dpmin[i][j] = Math.min(dpmin[i - 1][j + 1], Math.min(dpmin[i - 1][j - 1], dpmin[i - 1][j])) + A[i][j];
                    }
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < A[0].length; ++j) {
            min = Math.min(min, dpmin[A.length - 1][j]);
        }

        return min;
    }
}
