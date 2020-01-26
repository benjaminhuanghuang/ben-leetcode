package cn.huang.leetcode;

public class LC_0007_ReverseInteger {
    public static int reverse(int x) {
        long k = x;
        boolean isNegtive = false;
        if (k < 0) {
            k = - k;
            isNegtive = true;
        }

        long result = 0;
        while (k != 0) {
            result *= 10;
            result += k % 10;
            k /= 10;
        }

        if (result > Integer.MAX_VALUE)
            return 0;
        return isNegtive ? - ((int) result) : (int) result;
    }
}
