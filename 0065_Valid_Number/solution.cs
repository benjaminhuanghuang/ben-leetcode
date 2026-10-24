using System;

public class Solution065 {
    public bool IsNumber(string s) {
        s = s.Trim();
        var hasSign = false;
        var hasDot = false;
        var hasE = false;
        var hasNumber = false;

        foreach (char ch in s)
        {
            if (ch == '.' && !hasDot && !hasE)
            {
                hasDot = true;
                continue;
            }

            if ((ch == 'e' || ch == 'E') && !hasE && hasNumber)
            {
                hasE = true;
                hasDot = false;
                hasNumber = false;
                hasSign = false;
                continue;
            }

            if ((ch == '+' || ch == '-') && !hasSign && !hasNumber && !hasDot)
            {
                hasSign = true;
                continue;
            }

            if (!Char.IsNumber(ch))  
            {
                //除了数字，只能接受以上字符：e . + -
                return false;
            }

            hasNumber = true;
        }

        return hasNumber;
    }
}