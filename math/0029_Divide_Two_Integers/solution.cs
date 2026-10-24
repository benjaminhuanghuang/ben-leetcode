/*
29. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.


Next challenges: (H) Strobogrammatic Number III  (H) Best Meeting Point  (H) Smallest Rectangle Enclosing Black Pixels

*/
using System;

public class Solution029 {
    public int Divide_long(int dividend, int divisor) {
        if (divisor == 0) return Int32.MaxValue;
        var sign = !((dividend > 0) ^ (divisor > 0));

        long dividendlong = Math.Abs((long)dividend);
        long divisorlong = Math.Abs((long)divisor);

        long res = 0;

        while (dividendlong >= divisorlong)
        {
            long cur = 1;       // 商
            long start = divisorlong;    // 除数
            while ((start << 1) <= dividendlong)
            {
                start <<= 1;
                cur <<= 1;                 
            }                 
            dividendlong -= start;                 
            res += cur;             
        }             
        if (sign)             
        {                 
            if (res > int.MaxValue) return int.MaxValue;
            return (int)res;
        }
        else
        {
            if (-res < int.MinValue) return int.MaxValue;
            return (int)-res;
        }
    }
    // can not work for -2147483648 , -1, need use long type. Python does not have this issue.
    // 
    public int Divide(int dividend, int divisor) 
    {
        if (divisor == 0) return Int32.MaxValue;
        bool sign = !((dividend > 0) ^ (divisor > 0));

        dividend = Math.Abs(dividend);
        divisor = Math.Abs(divisor);

        int result = 0;
   
        while (dividend >= divisor)
        {
            int cur = 1;
            int start = divisor;
            while ((start << 1) <= dividend)
            {
                start <<= 1;
                cur <<= 1;                 
            }                 
            dividend -= start;                 
            result += cur;        
        }       
        if (sign)             
        {                 
            if (result > int.MaxValue) return int.MaxValue;
            return result;
        }
        else
        {
            if (-result < int.MinValue) return int.MaxValue;
            return -result;
        }
    }
}