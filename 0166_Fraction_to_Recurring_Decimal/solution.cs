/*
166. Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in 
string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Hint:

No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.

*/
using System;
using System.Text;
using System.Collections.Generic;

public class Solution166 {
    // before “.”,  divide numerator by denominator
    // if numerator mod denominator not equal to 0, add “.”
    // after “.”, analysis the numerator % denominator
    public string FractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
        {
            return "0";
        }

        var res = new StringBuilder();
        var hashtable = new Dictionary<long, int>();
        var sign = (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
        var denominatorlong = Math.Abs((long)denominator);
        var numeratorlong = Math.Abs((long)numerator);

        // before .
        res.Append(numeratorlong / denominatorlong);

        var remain = numeratorlong % denominatorlong;

        // add .
        if (remain != 0)
        {
            res.Append('.');
        }

        // after .
        var count = res.Length;
        while (remain != 0)
        {
            hashtable.Add(remain, count++);
            res.Append((remain * 10) / denominatorlong);
            var nextRemain = (remain * 10) % denominatorlong;
            if (hashtable.ContainsKey(nextRemain))
            {
                res.Insert(hashtable[nextRemain], '(');
                res.Append(')');
                break;
            }

            remain = nextRemain;
        }
        if (sign)
        {
            res.Insert(0, '-');
        }
        return res.ToString();
    }
}