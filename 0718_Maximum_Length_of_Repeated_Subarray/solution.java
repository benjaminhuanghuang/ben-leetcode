package cn.huang.leetcode;

/*
718. Maximum Length of Repeated Subarray   [Google]
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].

Note:

    1 <= len(A), len(B) <= 1000
    0 <= A[i], B[i] < 100

 */
public class LC_0718_MaximumLengthofRepeatedSubarray {
    /*
    最长连续公共子序列
    dp[i][j] 来存储A[i]和B[j]之前的LCS（最长公共子序列）；
    当A[n]=B[m]时，dp[i][j] = dp[i-1][j-1] + 1;max = Math.max(max, dp[i][j])
     */
    public int findLength(int[] A, int[] B) {
        if (A == null || B == null) return 0;
        int m = A.length;
        int n = B.length;
        int max = 0; //the length of longest common subarray end with A[i] and B[j]
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    if (A[i - 1] == B[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        max = Math.max(max, dp[i][j]);
                    }
                }
            }
        }
        return max;
    }

    /*
    时间复杂度：O(n^2)，空间复杂度：O(n)
     */
    public int findLength2(int[] A, int[] B) {
        int ans = 0;
        int[] dp = new int[A.length + 1];
        for (int j = 1; j <= B.length; j++) {
            for (int i = A.length; i >= 1; i--) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i] = dp[i - 1] + 1;
                } else {
                    dp[i] = 0;
                }
                ans = Math.max(ans, dp[i]);
            }
        }
        return ans;
    }
}
