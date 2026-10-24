package cn.huang.leetcode;

import java.util.HashSet;

/*
    202. Happy Number

    Write an algorithm to determine if a number is "happy".

    A happy number is a number defined by the following process: Starting with any positive integer,
    replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1
    (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this
    process ends in 1 are happy numbers.

    Example:

    Input: 19
    Output: true
    Explanation:
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1
 */
public class LC_0202_HappyNumber {
    public boolean isHappy(int n) {
        if (n < 1) {
            return false;
        }

        // 用于保存中间出现的结果
        HashSet<Integer> set = new HashSet<>(32);

        int tmp;
        int newN;

        // n不为1，并且n的值不能重复出现，否则会死循环
        while (n != 1 && !set.contains(n)) {
            set.add(n);
            newN = 0;
            while (n > 0) {
                tmp = n % 10;
                n /= 10;
                newN += tmp * tmp;
            }

            n = newN;
        }

        return n == 1;
    }
}
