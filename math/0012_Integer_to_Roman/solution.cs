/*
12. Integer to Roman  

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*/

public class Solution012 {
    public string IntToRoman(int num) {
        // 3999 : MMM CM XC IX
        string[] ch = new string[] { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        // 1, 4, 5, 9
        int[] value = new int[] { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string ans = "";
        for (int i=0; num != 0; ++i)
        {
            // Try to select the biggest roman number
            while (num >= value[i])
            {
                num -= value[i];
                ans += ch[i];
            }
        }
        return ans;
    }

    // http://www.cnblogs.com/grandyang/p/4123374.html
    string intToRoman(int num) {
        string res = "";
        string[] roman = {"M", "D", "C", "L", "X", "V", "I"};
        int[] value = {1000, 500, 100, 50, 10, 5, 1};
        
        for (int n = 0; n < 7; n += 2) {   // 1000, 100, 10
            int x = num / value[n];
            if (x < 4) 
            {
                for (int i = 1; i <= x; ++i)            // III
                    res += roman[n];
            } 
            else if (x == 4) 
                res = res + roman[n] + roman[n - 1];    // IV
            else if (x > 4 && x < 9) 
            {
                res += roman[n - 1];                    // VIII
                for (int i = 6; i <= x; ++i) 
                    res += roman[n];
            }
            else if (x == 9) 
                res = res + roman[n] + roman[n - 2];    // IX
            num %= value[n];            
        }
        return res;
    }
}