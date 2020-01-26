package cn.huang.leetcode;

import java.util.Arrays;

/*
956. Tallest Billboard

You are installing a billboard and want it to have the largest height.  The billboard will have two steel supports,
one on each side.  Each steel support must be an equal height.

You have a collection of rods which can be welded together.  For example, if you have rods of lengths 1, 2, and 3,
you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation.  If you cannot support the billboard, return 0.



Example 1:

Input: [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

Example 2:

Input: [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

Example 3:

Input: [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.



Note:

    0 <= rods.length <= 20
    1 <= rods[i] <= 1000
    The sum of rods is at most 5000.


 */
public class LC_0956_TallestBillboard {
    /*
    https://github.com/cherryljr/LeetCode/blob/master/Tallest%20Billboard.java
     */
    public int tallestBillboard(int[] rods) {
        int n = rods.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += rods[i];
        }

        // Initialization
        int[][] dp = new int[n + 1][sum + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        dp[0][0] = 0;

        // 01 Backpack Problem
        for (int i = 1; i <= n; i++) {
            int height = rods[i - 1];
            // Without the current height, the difference must be in [0, sum-height]
            for (int j = 0; j <= sum - height; j++) {
                if (dp[i - 1][j] < 0) {
                    continue;
                }
                // Not used
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                // Put on the taller one
                dp[i][j + height] = Math.max(dp[i][j + height], dp[i - 1][j]);
                // Put on the shorter one
                dp[i][Math.abs(j - height)] = Math.max(dp[i][Math.abs(j - height)], dp[i - 1][j] + Math.min(j, height));
            }
        }

        return dp[n][0];
    }

    /*
    Hua hua
    https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-956-tallest-billboard/
    https://www.youtube.com/watch?v=WqLslW2sFxU
     */
}
