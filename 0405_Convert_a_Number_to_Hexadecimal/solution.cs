/*
405. Convert a Number to Hexadecimal

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.


Example 1:
Input:
26

Output:
"1a"

Example 2:
Input:
-1

Output:
"ffffffff"
*/
public class Solution405 {
    public string ToHex(int num) {
        string res = "";
        // 有符号数右移， 左边会补上符号位
        for (int i = 0; num != 0 && i<8; ++i) 
        {
            int t = num & 0xf;
            if (t >= 10) 
                res = (char)('a' + t - 10) + res;
            else 
                res = (char)('0' + t) + res;
            num >>= 4;
        }
        return res=="" ? "0" : res;
    }
}