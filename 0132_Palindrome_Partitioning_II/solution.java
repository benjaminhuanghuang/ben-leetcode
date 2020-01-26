package cn.huang.leetcode;

/*
132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.


 */

/*
题意：找到把原字符串拆分成回文串的最小切割数，需要用动态规划Dynamic Programming来做，
从后往前推，递推公式为：dp[i] = min(dp[i], 1+dp[j+1] )    i<=j <n，
是否对于i到j之间的子字符串s[i][j]每次都判断一下是否是回文串，
其DP递推公式为P[i][j] = s[i] == s[j] && P[i+1][j-1]，其中P[i][j] = true if [i,j]为回文。
 */
public class LC_0132_PalindromePartitioning_II {
    /*
        https://www.youtube.com/watch?v=vunyW9zVrx4
     */
    public int minCut(String s) {
        int len = s.length();

        boolean[][] palindrome = new boolean[len][len];
        int dp[] = new int[len];
        dp[0] = 0;

        for (int i = 1; i < len; i++) {
            int minCuts = i;
            for (int j = 0; j <= i; j++) {
                if (s.charAt(i) != s.charAt(j)) {
                    palindrome[j][i] = false;
                    continue;
                }

                if (i == j || j == i - 1) {
                    palindrome[j][i] = true;
                } else {
                    palindrome[j][i] = palindrome[j + 1][i - 1];
                }

                if (palindrome[j][i]) {
                    minCuts = Math.min(minCuts, j == 0 ? 0 : dp[j - 1] + 1);
                }
            }

            dp[i] = minCuts;
        }

        return dp[len - 1];
    }
}
