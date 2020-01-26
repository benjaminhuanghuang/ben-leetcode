package cn.huang.leetcode;
/*
    788. Rotated Digits
    X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is
    different from X.  Each digit must be rotated - we cannot choose to leave it alone.

    A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to
    each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

    Now given a positive number N, how many numbers X from 1 to N are good?

    Example:
    Input: 10
    Output: 4
    Explanation:
    There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
    Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
 */
public class LC_0788_RotatedDigits {
    /*
        该数字中不含[3, 4, 7]，否则其倒影不是数字。
        该数字中必须包含[2, 5, 6, 9]中的至少一个，否则倒影和原数字相同
     */
    public int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            if (check(i)) ++res;
        }
        return res;
    }
    private boolean check(int k) {
        String str = Integer.toString(k);
        boolean flag = false;
        for (char c : str.toCharArray()) {
            if (c == '3' || c == '4' || c == '7') return false;
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true;;
        }
        return flag;
    }
}
