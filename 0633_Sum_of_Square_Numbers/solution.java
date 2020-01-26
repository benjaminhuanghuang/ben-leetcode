package cn.huang.leetcode;

/*
633. Sum of Square Numbers
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.
 */
public class LC_0633_SumofSquareNumbers {
    public boolean judgeSquareSum(int c) {
        int low = 0;
        int high = (int) Math.sqrt(c);
        while (low <= high) {
            int sum = low * low + high * high;
            if (sum < c) {
                low++;
            } else if (sum > c) {
                high--;
            } else {
                return true;
            }
        }
        return false;
    }
}
