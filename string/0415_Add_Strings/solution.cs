/*
415. Add Strings

Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

refer to #2. Add Two Numbers
*/
using System;
using System.Text;

public class Solution415 {
    public string AddStrings(string num1, string num2) {
        StringBuilder sb = new StringBuilder();
        int i1 = num1.Length -1;
        int i2 = num2.Length -1;
        int carry = 0;
        while( i1 >=0 || i2 >=0 || carry >0)
        {
            int total = carry;
            if (i1>=0)
            {
                total += num1[i1] - '0';
                i1 --;
            }
            if (i2>=0)
            {
                total += num2[i2] - '0';
                i2 --;
            }
            carry = total / 10;
            int sum = total % 10;
            sb.Insert(0, (char)(sum + '0'));
        }
        return sb.ToString();
    }
}