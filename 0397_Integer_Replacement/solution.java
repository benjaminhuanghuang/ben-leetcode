package cn.huang.leetcode;

/*
397. Integer Replacement

 Given a positive integer n and you can do operations as follow:

    If n is even, replace n with n/2.
    If n is odd, you can replace n with either n + 1 or n - 1.

What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1

Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1

 */
public class LC_0397_IntegerReplacement {
    public int integerReplacement(int n) {
        if (n == Integer.MAX_VALUE) {
            return 32;
        }
        int numOfRe = 0;
        while (n != 1) {
            if (n == 3) {
                return numOfRe + 2;
            }
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                if ((n / 2) % 2 == 1) {
                    n = n + 1;
                } else {
                    n = n - 1;
                }
            }
            numOfRe++;
        }
        return numOfRe;

    }
}
