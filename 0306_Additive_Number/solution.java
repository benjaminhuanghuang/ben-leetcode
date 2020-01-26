package cn.huang.leetcode;

/*
306. Additive Number

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent
number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

Example 2:

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199.
             1 + 99 = 100, 99 + 100 = 199

Follow up:
How would you handle overflow for very large input integers?
 */


import java.math.BigInteger;

/*
假设字符串为a[0-n]，第一个字符串是a[0-m]
如果a[0-n]是Additive 的，那么a[m-n]必然是Additive 的。
迭代递归就能判断了。
 */
public class LC_0306_AdditiveNumber {
    public boolean isAdditiveNumber(String num) {
        for (int i = 1; i <= num.length() >> 1; i++)
            for (int j = 1; j + i < num.length(); j++)  //
                if (isValid(num, num.substring(0, i), num.substring(i, i + j), i + j))
                    return true;
        return false;
    }

    private boolean isValid(String num, String first, String second, int index) {
        if (first.length() > 1 && first.startsWith("0")
                || second.length() > 1 && second.startsWith("0"))
            return false;
        if (index == num.length())
            return true;
        long sum = Long.parseLong(first) + Long.parseLong(second);
        if (num.startsWith(sum + "", index))
            if (isValid(num, second, sum + "", index + (sum + "").length())) return true;
        return false;
    }

    public boolean isValid(int i, int j, String num) {
        if (num.charAt(0) == '0' && i > 1)
            return false;
        if (num.charAt(i) == '0' && j > 1)
            return false;
        BigInteger x1 = new BigInteger(num.substring(0, i));
        BigInteger x2 = new BigInteger(num.substring(i, i + j));
        String sum;
        for (int start = i + j; start < num.length(); start += sum.length()) {
            x2 = x2.add(x1);
            x1 = x2.subtract(x1);
            sum = x2.toString();
            if (!num.startsWith(sum, start))
                return false;
        }
        return true;
    }

    public boolean isAdditiveNumber2(String num) {
        int len = num.length();
        for (int i = 1; i <= len / 2; i++) {
            for (int j = 1; Math.max(i, j) <= len - i - j; j++) {
                if (isValid(i, j, num)) {
                    return true;
                }
            }
        }
        return false;
    }
}
