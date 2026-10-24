using System;

public class Solution073 {
    public void SetZeroes_colrow(int[,] matrix) {
        var row = matrix.GetLength(0);
        var column = matrix.GetLength(1);

        var zerorow = new bool[row];
        var zerocolumn = new bool[column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (matrix[i, j] == 0)
                {
                    zerorow[i] = true;
                    zerocolumn[j] = true;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            if (zerorow[i])
            {
                for (int j = 0; j < column; j++)
                {
                    matrix[i, j] = 0;
                }
            }
        }

        for (int j = 0; j < column; j++)
        {
            if (zerocolumn[j])
            {
                for (int i = 0; i < row; i++)
                {
                    matrix[i, j] = 0;
                }
            }
        }
    }

    public void SetMatrixZeroes_MaxInt(int[][] matrix)
    {
        var m = matrix.Length;
        var n = matrix[0].Length;

        for (var i = 0; i < m; i++)
        {
            for (var j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (var x = 0; x < n; x++)
                    {
                        if (matrix[i][x] != 0) matrix[i][x] = Int32.MaxValue;
                    }
                    for (var y = 0; y < m; y++)
                    {
                        if (matrix[y][j] != 0) matrix[y][j] = Int32.MaxValue;
                    }
                }
            }
        }

        for (var i = 0; i < m; i++)
        {
            for (var j = 0; j < n; j++)
            {
                if (matrix[i][j] == Int32.MaxValue)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}