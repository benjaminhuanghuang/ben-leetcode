package cn.huang.leetcode;
/*
629. K Inverse Pairs Array

 Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.

We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.

Since the answer may be very large, the answer should be modulo 109 + 7.

Example 1:

Input: n = 3, k = 0
Output: 1
Explanation:
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.

Example 2:

Input: n = 3, k = 1
Output: 2
Explanation:
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

Note:

    The integer n is in the range [1, 1000] and k is in the range [0, 1000].

 */

/*
https://www.youtube.com/watch?v=d2Z7cGgxkeQ

Brute-force Time complexity: n^2 * n! 两重循环检查所有的pair，n个数可以组成n!个序列

 */
public class LC_0629_KInversePairsArray {
    public int kInversePairs(int n, int k) {
        long[][] dp = new long[n + 1][k + 1];

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                if (j - i >= 0)
                    dp[i][j] -= dp[i - 1][j - i];
                dp[i][j] += 1000000007;
                dp[i][j] %= 1000000007;
            }

        return (int) dp[n][k];

    }
}
