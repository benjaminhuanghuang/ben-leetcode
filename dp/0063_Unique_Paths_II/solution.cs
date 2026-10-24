public class Solution063 {
    public int UniquePathsWithObstacles(int[,] obstacleGrid) {
        var row = obstacleGrid.GetLength(0);
        var column = obstacleGrid.GetLength(1);

        var dp = new int[row, column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)                 
            {                     
                if (obstacleGrid[i, j] == 1)                     
                {                         
                    dp[i, j] = 0;                         
                    continue;                     
                }                     
                if (i == 0 && j == 0)                     
                {                         
                    dp[i, j] = 1;                     
                }                     
                else                     
                {                         
                    dp[i, j] = (i > 0 ? dp[i - 1, j] : 0) + (j > 0 ? dp[i, j - 1] : 0);
                }
            }
        }

        return dp[row - 1, column - 1];
    }
}