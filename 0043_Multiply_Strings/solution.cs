/*
43. Multiply Strings

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.

*/
using System.Text;

public class Solution043 {
    /*
        注意方向：两个数字从右向左，result从左向右
    */
    public string Multiply(string num1, string num2) {
        var res = new int[num1.Length + num2.Length];
        for (int i = num1.Length - 1; i >= 0; i--)
        {
            for (var j = num2.Length - 1; j >= 0; j--)
            {
                var sum = (num1[i] - '0')*(num2[j] - '0') + res[i + j + 1];

                res[i + j + 1] = sum%10;
                res[i + j] += sum/10;
            }
        }

        var sb = new StringBuilder();
        for (int i = 0; i < res.Length; i++)         
        {             
            // Skip the first 0 at res[0]
            if(sb.Length == 0 && res[i] == 0) continue;             
            sb.Append(res[i]);         
        }         
        return sb.Length > 0 ? sb.ToString() :"0";
    }

    public string Multiply_2(string num1, string num2) {
        var res = new int[num1.Length + num2.Length];
        for (int i = num1.Length - 1; i >= 0; i--)
        {
            for (var j = num2.Length - 1; j >= 0; j--)
            {
                res[i + j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        var sb = new StringBuilder();
        for (int i = 0; i < res.Length; i++)         
        { 
            int digit  = res[i] % 10;
            int carry = res[i] / 10;
            if (i < res.Length - 1)
                res[i+1] += carry;
            sb.Insert(0, digit.ToString());                
        }         
        return sb.Length > 0 ? sb.ToString() :"0";
    }
}