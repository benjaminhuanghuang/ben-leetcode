/*
74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the 
following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

public class Solution074 {
    public bool SearchMatrix(int[,] matrix, int target) {
        var cols = matrix.GetLength(1);

        var low = 0;
        var high = matrix.Length - 1;     // matrix.Length = col * row

        while (low <= high)             
        {                 
            var mid = (high - low)/2 + low;     
            // Key point:            
            var col = mid % cols;                 
            var row = mid / cols;                 
            if (matrix[row, col] == target)
            {                     
                return true;                 
            }                 
            else if (matrix[row, col] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
}