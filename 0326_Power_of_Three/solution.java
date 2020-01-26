package cn.huang.leetcode;

/*
    326. Power of Three
 */
public class LC_0326_PowerofThree {
    public boolean isPowerOfThree(int n) {
        if (n == 1) return true;

        boolean result = false;

        while (n > 0) {
            int m = n % 3;
            if (m == 0) {
                n = n / 3;
                if (n == 1)
                    return true;
            } else {
                return false;
            }
        }

        return result;
    }

    public boolean isPowerOfThree_Recursion(int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;

        if (n > 1)
            return n % 3 == 0 && isPowerOfThree_Recursion(n / 3);
        else
            return false;
    }
}
