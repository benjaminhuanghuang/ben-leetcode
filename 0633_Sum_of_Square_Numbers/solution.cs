/*
633. Sum of Square Numbers
Given a non-negative integer c, your task is to decide whether there're two integers a and b such 
that a^2 + b^2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
 */

using System;
public class Solution633
{
    public bool JudgeSquareSum(int c)
    {
        for (int a = 0; a < (int)(Math.Sqrt(c) + 1); a++)
        {
            int squareOfb = c - a * a;
            int b = (int)Math.Sqrt(squareOfb);
            if (b * b == squareOfb)
                return true;
        }
        return false;
    }
}