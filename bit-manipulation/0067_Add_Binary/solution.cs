/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

using System.Text;

public class Solution067 {
    public string AddBinary(string a, string b) {
        var carryover = 0;
        var stringBuilder = new StringBuilder();

        for (int startA = a.Length - 1, startB = b.Length - 1; startA >= 0 || startB >= 0; startA--, startB--)
        {
            var curA = startA >= 0 ? a[startA] - '0' : 0;
            var curB = startB >= 0 ? b[startB] - '0' : 0;
            var sum = curA + curB + carryover;

            if (sum > 1)
            {
                stringBuilder.Insert(0, sum % 2);
                carryover = 1;
            }
            else
            {
                stringBuilder.Insert(0, sum);
                carryover = 0;
            }
        }

        if (carryover == 1)
        {
            stringBuilder.Insert(0, '1');
        }

        return stringBuilder.ToString();
    }
}