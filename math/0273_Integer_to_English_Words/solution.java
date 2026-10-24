package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
273. Integer to English Words

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"

Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"


 */
public class LC_0273_IntegertoEnglishWords {
    String[] units = {"", " Thousand", " Million", " Billion"};
    String[] num0To9 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    String[] num10To19 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    String[] num10To90 = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        String res = "";
        int count = 0; //记录当前三位数下后面跟的单位

        while (num > 0) {
            String temp = "";
            temp = units[count]; //记录当前三位数下后面跟的单位
            int cur = num % 1000; //每三位一读，从后往前
            String pre = convert(cur); //转化当前数字最后的三位数
            if (pre == "")
                temp = ""; //如果是"000"，那么就等于什么都没发生，舍弃单位
            else
                temp = pre + temp; //否则结合结果和单位
            if (res.length() != 0 && res.charAt(0) != ' ') //处理一下加上单位的空格情况
                res = temp + " " + res;
            else
                res = temp + res;
            num = num / 1000; //处理往前三位数
            count++;
        }
        return res;
    }

    // convert number less than 1000
    public String convert(int num) {
        if (num == 0)
            return "";
        if (num < 10)
            return num0To9[num];
        else if (num >= 10 && num <= 19)
            return num10To19[num - 10];
        else if (num >= 20 && num <= 99) {
            if (num % 10 == 0) return num10To90[num / 10 - 1];
            else {
                String s1 = num0To9[num % 10];
                String s2 = num10To90[num / 10 - 1];
                return s2 + " " + s1;
            }
        } else {
            if (num % 100 == 0)
                return num0To9[num / 100] + " Hundred";
            else {
                String temp = convert(num % 100);
                return convert(num - num % 100) + " " + temp;
            }
        }
    }
}
