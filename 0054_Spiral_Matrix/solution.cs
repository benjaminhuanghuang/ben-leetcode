/*
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

using System.Collections.Generic;

public class Solution054 {
    public IList<int> SpiralOrder(int[,] matrix) {
        int left = 0;
        int right = matrix.GetLength(1) - 1;
        int top = 0;
        int bottom = matrix.GetLength(0) -1;
        List<int> res = new List<int>();
        int direct = 0;
        while(left <= right && top <= bottom)
        {
            // top 
            if (direct == 0){
                for (int i = left; i <= right ; i++)
                    res.Add(matrix[top, i]);
                top ++;
            }
            // right  
            if (direct == 1)
            {
                for (int i = top; i <= bottom ; i++)
                    res.Add(matrix[i, right]);
                right --;  
            }
          
            // bottom
            if (direct == 2){
                for (int i = right; i >= left ; i--)
                    res.Add(matrix[bottom, i]);
                bottom --;
            }

            // left
            if (direct == 3)
            {
                for (int i = bottom; i >= top; i--)
                    res.Add(matrix[i, left]);
                left ++;
            }
            direct = (direct + 1) %4;
        }
        return res.ToArray();
    }
}