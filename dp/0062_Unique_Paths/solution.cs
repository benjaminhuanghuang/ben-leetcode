/*
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

/*
算解个数的题多半是用DP。而这两题状态也非常显然，dp[i][j]表示从起点到位置(i, j)的路径总数。
1. 由于只能向右和左走，所以对于(i, j)来说，只能从左边或上边的格子走下来：
dp[i][j] = dp[i-1][j] + dp[i][j-1]
2. 对于网格最上边和最左边，则只能从起点出发直线走到，dp[0][j] = dp[i][0] = 1
*/
public class Solution062 {
    public int UniquePaths_DP(int m, int n)
    {
        var dp = new int[m,n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j <n; j++)
            {
                if (i == 0 || j == 0)
                {
                    //网格最上边和最左边，则只能从起点出发直线走到，dp[0][j] = dp[i][0] = 1
                    dp[i, j] = 1;
                }
                else
                {
                    dp[i, j] = dp[i - 1, j] + dp[i, j - 1];
                }
            }
        }

        return dp[m-1, n-1];
    }

    // Time limit execeed.
    public int UniquePaths(int m, int n)
    {
        return this.UniquePathsRecursion(0, 0, m, n);
    }

    private int UniquePathsRecursion(int row, int column, int m, int n)
    {
        if (row == m && column == n)
        {
            return 1;
        }

        if (row == m)
        {
            return this.UniquePathsRecursion(m, column + 1, m, n);
        }

        if (column == n)
        {
            return this.UniquePathsRecursion(row + 1, n, m, n);
        }

        return this.UniquePathsRecursion(row + 1, column, m, n) + this.UniquePathsRecursion(row, column + 1, m, n);
    }
}