package cn.huang.leetcode;

/*
43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.


 */
public class LC_0043_MultiplyStrings {
    /*
       要画图，举例子
       注意方向：两个数字从右向左，result从左向右
       从个位数乘起, 乘得的结果放在res的[i+j][i+j+1]上 [i+j+1]是低位
     */
    public String Multiply(String num1, String num2) {
        int[] res = new int[num1.length() + num2.length()];
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                {
                    int sum = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + res[i + j + 1];

                    res[i + j + 1] = sum % 10;
                    res[i + j] += sum / 10;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < res.length; i++) {
            // Skip the first 0 at res[0]
            if (sb.length() == 0 && res[i] == 0) continue;
            sb.append(res[i]);
        }
        return sb.length() > 0 ? sb.toString() : "0";
    }


    public String multiply_2(String num1, String num2) {
        int[] res = new int[num1.length() + num2.length()];

        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                res[i + j] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < res.length; i++) {
            int digit = res[i] % 10;
            int carry = res[i] / 10;
            if (i < res.length - 1)
                res[i + 1] += carry;
            sb.insert(0, digit);
        }
        return sb.length() > 0 ? sb.toString() : "0";
    }
}
