/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

public class Solution059 {
    public int[,] GenerateMatrix(int n) {
        var matrix = new int[n, n];
        int top = 0;
        int left = 0;
        int right = n-1;
        int bottom = n-1;

        int current = 0;
        while (current < n*n)
        {
                for (int i = left; i <= right ; i++)
                {
                    current++;
                    matrix[top, i] = current;
                }
                top ++;
            
                for (int i = top; i <= bottom ; i++)
                {
                    current++;
                    matrix[i, right] = current;
                }
                right --;
            
                for (int i = right; i >= left; i--)
                {
                    current++;
                    matrix[bottom, i] = current;
                }
                bottom --;
            
                for (int i = bottom; i >= top; i--)
                {
                    current++;
                    matrix[i, left] = current;
                }
                left ++;
            }

        return matrix;
    }
}