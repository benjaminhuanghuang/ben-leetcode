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