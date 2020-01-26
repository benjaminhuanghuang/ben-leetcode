package cn.huang.leetcode;

/*
926. Flip String to Monotone Increasing

A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed
by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.
 */
public class LC_0926_FlipStringtoMonotoneIncreasing {
    /*
    https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-926-flip-string-to-monotone-increasing/
     */
    public int minFlipsMonoIncr(String S) {
        int n = S.length();
        int[][] dp = new int[n + 1][2];

        for (int i = 1; i <= n; ++i) {
            if (S.charAt(i - 1) == '0') {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]) + 1;
            } else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        return Math.min(dp[n][0], dp[n][1]);
    }

    public int minFlipsMonoIncr_v1(String S) {
        int n = S.length();
        int[] l = new int[n + 1]; // 1 -> 0
        int[] r = new int[n + 1]; // 0 -> 1

        l[0] = S.charAt(0) - '0';
        r[n - 1] = '1' - S.charAt(n - 1);

        for (int i = 1; i < n; ++i)
            l[i] = l[i - 1] + S.charAt(i) - '0';
        for (int i = n - 2; i >= 0; --i)
            r[i] = r[i + 1] + '1' - S.charAt(i);

        int ans = r[0]; // all 1s.
        for (int i = 1; i <= n; ++i)
            ans = Math.min(ans, l[i - 1] + r[i]);
        return ans;
    }
}
