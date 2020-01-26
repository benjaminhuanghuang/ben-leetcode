package cn.huang.leetcode;
/*
600. Non-negative Integers without Consecutive Ones

Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary
representations do NOT contain consecutive ones.

Example 1:

Input: 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.

Note: 1 <= n <= 109

 */

/*
这道题给了我们一个数字，让我们求不大于这个数字的所有数字中，其二进制的表示形式中没有连续1的个数。
int转2进制string的API！！

先用dp找出在k位二进制长度的数有多少满足条件的。a[i]表示以0为结尾的长度为i + 1的满足条件的数字个数，b[i]表示1为结尾的。

再找a[n - 1] + b[n - 1]里面overcount了多少，只有当连续两位为0时，b[i]是overcount的。11、01、10都能cover到a[i]和b[i]
 */
public class LC_0600_Non_negativeIntegerswithoutConsecutiveOnes {
    public int findIntegers(int num) {
        StringBuilder sb = new StringBuilder(Integer.toBinaryString(num)).reverse();
        int n = sb.length();
        int[] a = new int[n];
        int[] b = new int[n];
        a[0] = 1;
        b[0] = 1;
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }
        int res = a[n - 1] + b[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (sb.charAt(i) == '0' && sb.charAt(i + 1) == '0') {
                res -= b[i];
            }
            if (sb.charAt(i) == '1' && sb.charAt(i + 1) == '1') {
                break;
            }
        }
        return res;
    }
}
