package cn.huang.leetcode;

import java.util.Arrays;

/*
279. Perfect Squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 */
public class LC_0279_PerfectSquares {
    /*
    用 dp[i] 数组存储第 i 个数的完美平方数。递推式为：dp[i] = Math.max(dp[j] + dp[i-j], dp[i]，
    认为 i 的完全平方数是从和为 i 的两个完全平方数 dp[j] 和 dp[i-j]之和，然后从中取最小。
     */
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[1] = 1;
        for(int i = 1; i <= n; i++) {
            int sqr = (int)Math.sqrt(i);
            if(sqr * sqr == i) dp[i] = 1;  //如果 i 本身是个平方数，就将 dp[i] 置1
            else {
                for(int j = 1; j <= i/2; j++) {
                    dp[i] = Math.min(dp[j] + dp[i-j], dp[i]);  //从0开始遍历所有和为 i 的 dp，使得 dp[i]取最小
                }
            }
        }
        return dp[n];
    }
}
