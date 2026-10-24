using System;
using System.Collections.Generic;

public class Solution498
{
    public int[] FindDiagonalOrder(int[,] matrix)
    {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        var arr = new int[rows * cols];

        int row = 0;
        int col = 0;
        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = matrix[row, col];
            if ((row + col) % 2 == 0)  // moving up
            {
                if (col == cols - 1)
                    row++;
                else if (row == 0)
                    col++;
                else
                {
                    row--;
                    col++;
                }
            }
            else //going down
            {
                if (row == rows - 1)
                    col++;
                else if (col == 0)
                    row++;
                else
                {
                    row++;
                    col--;
                }
            }
        }
        return arr;
    }
}
/*
 int[,] matrix = new int[,] { {1, 2,3}, {4,5, 6},{7,8,9} };
        var s = new Solution498();
        var array = s.FindDiagonalOrder(matrix);
        foreach (var i in array)
        {
            Console.WriteLine(i);
        }
*/
