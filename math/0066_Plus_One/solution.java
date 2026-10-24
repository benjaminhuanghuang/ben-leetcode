package cn.huang.leetcode;

public class LC_0066_PlusOne {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for (int i = digits.length - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;   // digits[i] == 9
        }
        int[] res = new int[n + 1];
        res[0] = 1;
        return res;
    }
}
