package cn.huang.leetcode;

/*
62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28


 */
public class LC_0062_UniquePaths {
    /*
    算解个数的题多半是用DP。dp[i][j]表示从起点到位置(i, j)的路径总数。
    1. 由于只能向右和左走，所以对于(i, j)来说，只能从左边或上边的格子走下来：
    dp[i][j] = dp[i-1][j] + dp[i][j-1]
    2. 对于网格最上边和最左边，则只能从起点出发直线走到，dp[0][j] = dp[i][0] = 1
     */
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    //网格最上边和最左边，则只能从起点出发直线走到，dp[0][j] = dp[i][0] = 1
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
}
