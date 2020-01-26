/*
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following 
properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

public class Solution240 {
    // O(m + n)
    public bool SearchMatrix(int[,] matrix, int target) {
        int col = matrix.GetLength(1);
        for(int row =0; row < matrix.GetLength(0); row++)
        {
            while(col >=0 && matrix[row, col] > target)
            {
                col --;
            }
            if (matrix[row, col] == target)
                return true;
        }
        return false;
    }
    
    // bin search 0(m*LogN)
    public bool SearchMatrix_Bin(int[,] matrix, int target) {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        int row = 0, col = cols - 1;

        while (row < rows && col >-0)
        {
            if (matrix[row, col] == target)
                return true;
            else if(matrix[row, col] < target)
                row ++;
            else
                col --;
        }
        return false;
    }
}