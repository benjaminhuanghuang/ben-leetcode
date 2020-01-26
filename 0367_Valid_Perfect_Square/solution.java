package cn.huang.leetcode;

/*
367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square
else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/
public class LC_0367_ValidPerfectSquare {
    public boolean isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long t = mid * mid;
            if (t == num)
                return true;
            else if (t < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    // Hua hua
    // https://www.youtube.com/watch?v=v57lNF2mb_s
    public boolean isPerfectSquare2(int num) {
        // 左闭右开， 所以right = num +1
        long left = 0, right = num + 1;
        while (left < right) {
            long mid = left + (right - left) / 2;
            long t = mid * mid;
            if (t == num)
                return true;
            else if (t < num)
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }
}
