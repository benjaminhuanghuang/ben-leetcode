package cn.huang.leetcode;

import java.util.Arrays;

/*
738. Monotone Increasing Digits

 Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:

Input: N = 10
Output: 9

Example 2:

Input: N = 1234
Output: 1234

Example 3:

Input: N = 332
Output: 299

 */
public class LC_0738_MonotoneIncreasingDigits {
    /*
    http://www.cnblogs.com/grandyang/p/8068326.html
    要找到从后往前遍历的"最后"一个值升高的位置，让前一位减1，并把当前位以及后面的所有位都变成9，就可以得到最大的单调递增数
     */
    public int monotoneIncreasingDigits(int N) {
        char[] digit = (N + "").toCharArray();
        int flag = digit.length;
        for (int i = digit.length - 1; i > 0; i--) {
            if (digit[i] < digit[i - 1]) {
                digit[i - 1]--;
                flag = i;
            }
        }
        Arrays.fill(digit, flag, digit.length, '9');
        return Integer.parseInt(new String(digit));
    }
}
