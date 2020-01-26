package cn.huang.leetcode;

/*
906. Super Palindromes

Let's say a positive integer is a superpalindrome if it is a palindrome, and it is also the square of a palindrome.

Now, given two positive integers L and R (represented as strings), return the number of superpalindromes in the
inclusive range [L, R].



Example 1:

Input: L = "4", R = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.



Note:

    1 <= len(L) <= 18
    1 <= len(R) <= 18
    L and R are strings representing integers in the range [1, 10^18).
    int(L) <= int(R)

 */
/*
统计[L, R]区间内“超级回文数”的个数。“超级回文数”的定义是，它是一个回文数，且也是一个回文数的平方。保证L <= R <= 10^18。
https://zhanghuimeng.github.io/post/leetcode-906-super-palindromes/
 */
public class LC_0906_SuperPalindromes {
    public int superpalindromesInRange(String L, String R) {
        Long l = (long) Math.sqrt(Long.parseLong(L));
        Long r = (long) Math.sqrt(Long.parseLong(R));
        int re = 0;
        for (int odd = 0; odd <= 1; odd++) {
            long core = 1;
            long num = getP(core, odd == 0);
            while (num <= r) {
                if (num >= l) {
                    if (isP(num * num)) re++;
                }
                num = getP(++core, odd == 0);
            }
        }
        return re;
    }

    private boolean isP(long num) {
        long n = num;
        long tmp = 0;
        while (num > 0) {
            tmp = tmp * 10 + num % 10;
            num = num / 10;
        }
        return tmp == n;
    }

    private long getP(long core, boolean isOdd) {
        long re = core;
        if (isOdd) {
            if (re < 10) return re;
            else re /= 10;
        }
        while (core > 0) {
            re = re * 10 + core % 10;
            core /= 10;
        }
        return re;
    }
}
