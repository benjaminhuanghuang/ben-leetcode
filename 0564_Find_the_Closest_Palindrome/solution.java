package cn.huang.leetcode;
/*
564. Find the Closest Palindrome

Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:

Input: "123"
Output: "121"

Note:

    The input n is a positive integer represented by string, whose length will not exceed 18.
    If there is a tie, return the smaller one as answer.

 */

import java.util.HashSet;

/*
给定整数n，寻找距离n最近（不包含n）的回文数。两个整数的距离是指其差的绝对值。

注意：

    n是字符串表示的正整数，长度不超过18。
    如果距离相等，返回值较小的整数。

解题思路：

记n的前半部分为p，分别用p，p - 1，p + 1及其逆序串拼接成长度为奇数或者偶数的回文串。

假设n的长度为m， p的长度应分别取m / 2，m / 2 + 1。

另外需要考虑进位时的边界情况，比如测试用例：11, 1001, 999
 */
public class LC_0564_FindtheClosestPalindrome {
    public String nearestPalindromic(String n) {
        long num = Long.parseLong(n), res = 0, len = n.length(), minDiff = Integer.MAX_VALUE;

        HashSet<Long> set = new HashSet<>();
        set.add((new Double(Math.pow(10, len) + 1)).longValue());
        set.add((new Double(Math.pow(10, len - 1) - 1)).longValue());

        long leftNum = Long.parseLong(n.substring(0, (int) (len + 1) >> 1));

        for (int i = -1; i <= 1; i++) {
            String left = String.valueOf(leftNum + i);
            String str;

            if (len % 2 == 0) {
                StringBuilder sb = new StringBuilder(left);
                str = left + sb.reverse().toString();
            } else {
                StringBuilder sb = new StringBuilder(left.substring(0, left.length() - 1));
                str = left + sb.reverse().toString();
            }

            set.add(Long.parseLong(str));
        }

        set.remove(num);
        for (Long a : set) {
            Long diff = Math.abs(a - num);
            if (diff < minDiff) {
                minDiff = diff;
                res = a;
            } else if (diff == minDiff) {
                res = Math.min(res, a);
            }
        }

        return String.valueOf(res);
    }
}
