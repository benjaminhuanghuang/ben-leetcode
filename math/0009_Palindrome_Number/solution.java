package cn.huang.leetcode;

public class LC_0009_PalindromeNumber {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;

        int n = x;
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return n == rev;
    }
}
