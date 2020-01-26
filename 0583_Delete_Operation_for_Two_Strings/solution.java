package cn.huang.leetcode;

/*
583. Delete Operation for Two Strings

Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where
in each step you can delete one character in either string.

Example 1:

Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Note:

    The length of given words won't exceed 500.
    Characters in given words can only be lower-case letters.

 */
public class LC_0583_DeleteOperationforTwoStrings {
    /*
    实际上就是求两个字符串的相同部分，再用两个字符串的长度减去公共部分的长度，加和即为需要改变的次数。
     */
    public int minDistance(String word1, String word2) {
        int common = lcs(word1, word2);
        return word2.length() + word1.length() - 2 * common;
    }

    /*
        Find Longest Common Subsequence
         https://www.youtube.com/watch?v=NnD96abizww
     */
    public int lcs(String s, String t) {
        if (s == null || s.length() == 0 || t == null || t.length() == 0) return 0;

        int len1 = s.length(), len2 = t.length();

        int[][] dp = new int[len1 + 1][len2 + 1];

        int max = 0;

        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }

                max = Math.max(max, dp[i][j]);
            }
        }

        return max;
    }
}
