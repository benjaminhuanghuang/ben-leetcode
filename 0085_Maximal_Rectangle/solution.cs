/*
85. Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/
using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;


public class Solution085 {
    public int maxRect(char[,] matrix) {
        var maxRect = 0;
        var row = matrix.GetLength(0);
        var column = matrix.GetLength(1);

        var dp = new int[column];
        var mystack = new Stack<int>();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (matrix[i, j] == '0')
                {
                    dp[j] = 0;
                }
                else
                {
                    dp[j] += 1;
                }
            }

            for (int j = 0; j < column; j++)
            {                     
                while (mystack.Any() && dp[mystack.Peek()] >= dp[j])
                {
                    var top = mystack.Pop();
                    var previous = mystack.Any() ? mystack.Peek() : -1;

                    maxRect = Math.Max(maxRect, dp[top] * (j - previous - 1));
                }

                mystack.Push(j);
            }

            while (mystack.Any())
            {
                var top = mystack.Pop();
                var previous = mystack.Any() ? mystack.Peek() : -1;

                maxRect = Math.Max(maxRect, dp[top] * (top - previous));
            }
        }

        return maxRect;
    }

    //https://discuss.leetcode.com/topic/6650/share-my-dp-solution
    //https://miafish.wordpress.com/2015/04/09/leetcode-ojc-maximal-rectangle/
    public int MaximalRectangle_2(char[,] matrix) {
        var res = 0;
        var row = matrix.GetLength(0);
        var column = matrix.GetLength(1);

        var left = new int[column];
        var right = Enumerable.Repeat(column, column).ToArray();
        var heights = new int[column];
        for (int i = 0; i < row; i++)
        {
            var curleft = 0;
            var curright = column;
            for (int j = 0; j < column; j++)             
            {                 
                if (matrix[i, j] == '0')                 
                {                     
                    heights[j] = 0;                 
                }                 
                else                 
                {                     
                    heights[j]++;                 
                }                 
                if (matrix[i, j] == '0')                 
                {                     
                    left[j] = 0;                     
                    curleft = j + 1;                 
                }                 
                else                 
                {                     
                    left[j] = Math.Max(left[j], curleft);                 
                }             
            }             
            for (int j = column - 1; j >= 0; j--)
            {
                if (matrix[i, j] == '0')
                {
                    right[j] = column;
                    curright = j;
                }
                else
                {
                    right[j] = Math.Min(right[j], curright);
                }
            }

            for (int j = 0; j < column; j++)
            {
                res = Math.Max(res, heights[j] * (right[j] - left[j]));                    
            }
        }

        return res;      
    }
}
