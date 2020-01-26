/*
7. Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/

using System;

public class Solution007 {
    // notice overflow!!!
    public int Reverse_NotGood(int x) {
        bool positive = x > 0;
        if (!positive)
        {
            // note!  -2147483648 = -(-2147483648)                         
            x = -x;
        }
        //long result = x %10;
        //x = x /10;
        long result=0;
        while (x > 0)
        {
            result = x % 10 + result*10;
            x = x /10;
        }
        if (!positive)
        {
            result = -result;
        }
        if (result >= int.MaxValue || result <= int.MinValue)
            result =0;
        return (int)result;
    }

    public int Reverse(int x) {
        bool positive = x > 0;
        // note!  -2147483648 = -(-2147483648)
        long LongX = positive? x: -x;
        long result=0;
        while (LongX > 0)
        {
            result = LongX % 10 + result*10;
            LongX = LongX /10;
        }
        if (!positive)
        {
            result = -result;
        }
        if (result >= int.MaxValue || result <= int.MinValue)
            result =0;
        return (int)result;
    }

    public int Reverse2(int x)
    {
        long res = 0;
        while (x != 0)
        {
            res = checked(res * 10 + x % 10);
            x /= 10;
        }

        if (res < int.MinValue || res > int.MaxValue) return 0;
        return (int)res;
    }
}