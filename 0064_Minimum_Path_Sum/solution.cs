/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom 
right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/


using System;

public class Solution064 {
    public int MinPathSum(int[,] grid) {
        int rows = grid.GetLength(0);
        int cols = grid.GetLength(1);
        var dp = new int[rows, cols];

        dp[0, 0] = grid[0,0];
        for (int i = 1; i < rows; i++)
        {
            // set first col
            dp[i, 0] = dp[i - 1, 0] + grid[i, 0];
        }
        for (int i = 1; i < cols; i++)
        {
            //set first row
            dp[0, i] = dp[0, i - 1] + grid[0, i];
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                dp[i, j] = Math.Min(dp[i - 1, j] + grid[i,j], dp[i, j - 1] + grid[i,j]);
            }
        }

        return dp[rows - 1, cols - 1];
    }
}