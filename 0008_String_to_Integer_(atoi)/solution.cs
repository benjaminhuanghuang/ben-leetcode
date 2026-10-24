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