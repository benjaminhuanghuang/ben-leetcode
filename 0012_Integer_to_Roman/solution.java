package cn.huang.leetcode;

/*
12. Integer to Roman [13]
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"

Example 2:

Input: 4
Output: "IV"

Example 3:

Input: 9
Output: "IX"

Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


 */
public class LC_0012_IntegertoRoman {
    public String intToRoman(int num) {
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < values.length; i++) {
            while (num >= values[i]) {
                num -= values[i];
                sb.append(strs[i]);
            }
        }
        return sb.toString();
    }

    public String intToRoman2(int num) {
        String res = "";
        String[] roman = {"M", "D", "C", "L", "X", "V", "I"};
        int[] value = {1000, 500, 100, 50, 10, 5, 1};

        for (int n = 0; n < roman.length; n += 2) {   // 1000, 100, 10
            int x = num / value[n];
            if (x < 4) {
                for (int i = 1; i <= x; ++i)            // III
                    res += roman[n];
            } else if (x == 4)
                res = res + roman[n] + roman[n - 1];    // IV
            else if (x > 4 && x < 9) {
                res += roman[n - 1];                    // VIII
                for (int i = 6; i <= x; ++i)
                    res += roman[n];
            } else if (x == 9)
                res = res + roman[n] + roman[n - 2];    // IX
            num %= value[n];
        }
        return res;
    }
}

