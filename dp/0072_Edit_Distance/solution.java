package cn.huang.leetcode;
/*
72. Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


 */


public class LC_0072_EditDistance {
    /*
       https://www.youtube.com/watch?v=iHtd2KjWX_c
       dp[i][j] 表示 从word1 到i 的位置 转换到 word2 到j的位置，所需要的最少步骤

       字符串中的字符相等：dp[i][j] = dp[i-1][j-1]
       字符串中的字符不相等：
            insert: dp[i][j] = dp[i][j-1] + 1
            delete: dp[i][j] = dp[i-1][j] + 1
            replace: dp[i][j] = dp[i-1][j -1 ] + 1

     */
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        dp[0][0] = 0;

        for (int i = 1; i <= len1; i++) {
            dp[i][0] = i;  //  删除i个字符得到空字符串
        }
        for (int i = 1; i <= len2; i++) {
            dp[0][i] = i;  // 空字符串添加i个字符得到串2
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        return dp[len1][len2];
    }
}
