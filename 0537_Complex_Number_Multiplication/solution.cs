/*
537. Complex Number Multiplication

Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to 
the range of [-100, 100]. And the output should be also in this form.

 */
using System;

public class Solution537
{
    public string ComplexNumberMultiply(string a, string b)
    {
        if (a == null || a.Length == 0 || b == null || b.Length == 0)
            return "0";

        int realA = int.Parse(a.Split('+')[0]);
        int virtualA = int.Parse(a.Split('+')[1].Substring(0, a.Split('+')[1].Length - 1));

        int realB = int.Parse(b.Split('+')[0]);
        int virtualB = int.Parse(b.Split('+')[1].Substring(0, b.Split('+')[1].Length - 1));

        int r = realA * realB - virtualA * virtualB;
        int v = realA * virtualB + virtualA * realB;

        return $"{r}+{v}i";
    }
}


/*

    var s = new Solution537();
    var res = s.ComplexNumberMultiply("1+-1i", "1+-1i");
    Console.WriteLine(res);

 */