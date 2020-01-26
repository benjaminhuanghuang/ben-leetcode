/*
8. String to Integer (atoi)

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see 
below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/

public class Solution008 {
    public int MyAtoi(string str) {
        int sign = 1;
        str = str.Trim();
        if (str.Length == 0)
            return 0;
        int index = 0;
        if (str[0] == '-' || str[0]=='+')
        {
            sign = str[0] == '+' ? 1 : -1;
            index++;
        }
        // if use int type, result will overflow
        long result = 0;
        while (index < str.Length)
        {
            if (!char.IsNumber(str[index]))
                break;
            result = result * 10 + (str[index] - '0');
            if (result * sign > int.MaxValue)
                return int.MaxValue;
            if (result * sign < int.MinValue)
                return int.MinValue;
            index++;
        }
        return (int)result * sign;
    }
}