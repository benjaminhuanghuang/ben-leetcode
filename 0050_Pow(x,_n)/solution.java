package cn.huang.leetcode;
/*
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]


 */
public class LC_0050_Powxn {
    public double myPow(double x, int n) {
        if (n>=0)
            return this.powerHelper(x, n);
        else
            return 1/ this.powerHelper(x, -n);
    }
    // x^n = x^(n/2)*x^(n/2)*x^(n%2)
    private double powerHelper(double x, int n)
    {
        if (n ==0)
            return 1;
        double res = this.powerHelper(x, n /2);
        res *= res;
        if (n % 2 != 0)
        {
            res *= x;
        }
        return res;
    }
}
