package cn.huang.leetcode;

/*
504. Base 7
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
 */
public class LC_0504_Base7 {
    public String convertToBase7(int num) {
        if(num ==0)
            return "0";

        String res = "";
        boolean isNegative = num < 0;
        if(isNegative)
            num= -num;

        while(num>0)
        {
            res = num % 7 + res;
            num = num /7;
        }

        if(isNegative)
            res = "-"+ res;
        return res;
    }
}
