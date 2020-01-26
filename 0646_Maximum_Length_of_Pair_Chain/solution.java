package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Comparator;

/*
646. Maximum Length of Pair Chain

 */
public class LC_0646_MaximumLengthofPairChain {
    public int findLongestChain(int[][] pairs) {
        int m = pairs.length;
        int[] dp = new int[m];
        Arrays.sort(pairs, Comparator.comparingInt(a -> a[0]));
        Arrays.fill(dp, 1);
        int max = 1;

        for (int i = 1; i < m; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
