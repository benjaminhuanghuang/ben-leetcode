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