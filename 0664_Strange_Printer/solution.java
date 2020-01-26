package cn.huang.leetcode;

/*
664. Strange Printer

 There is a strange printer with the following two special requirements:

    The printer can only print a sequence of the same character each time.
    At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.

Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

Example 1:

Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:

Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

Hint: Length of the given string will not exceed 100.
 */
public class LC_0664_StrangePrinter {
    public int strangePrinter(String s) {
        int n = s.length();
        if (n == 0) return 0;
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        char[] cs = s.toCharArray();

        for (int d = 1; d < n; d++) {
            for (int i = 0; i + d < n; i++) {
                dp[i][i + d] = d + 1;
                for (int j = i + 1; j <= i + d; j++) {
                    int t = dp[i][j - 1] + dp[j][i + d];
                    if (cs[j - 1] == cs[i + d]) t--;
                    dp[i][i + d] = Math.min(dp[i][i + d], t);
                }
            }
        }

        return dp[0][n - 1];
    }
}
