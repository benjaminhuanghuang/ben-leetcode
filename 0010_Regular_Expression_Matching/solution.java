package cn.huang.leetcode;
/*

10. Regular Expression Matching
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.
 */


/*
https://www.youtube.com/watch?v=c5vsle60Uw8
https://www.youtube.com/watch?v=DqhPJ8MzDKM

    dp[i][j] 表示s[0到i]与p[0到j]是否match, i, j为字符个数
    if p[j] == '.', dp[i][j] = dp[i-1][j-1]
    if p[j] == * there 2 cases
        if p[j-1] != s[i] : dp[i][j] = dp[i][j-2]  // "baab", "bc*aa"
        if p[j-1] == s[i] or p[j-1] =='.'

 */
public class LC_0010_RegularExpressionMatching {
    public boolean isMatch(String s, String p) {
        if (s == null || p == null)
            return false;
        int m = s.length(), n = p.length();

        // dp[i][j] 表示s[0到i]与p[0到j]是否match
        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;   // empty str matches empty pattern

        for (int i = 0; i < n; i++) {
            if (p.charAt(i) == '*' && dp[0][i - 1])
                dp[0][i + 1] = true;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p.charAt(j) == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                if (p.charAt(j) == s.charAt(i))
                    dp[i + 1][j + 1] = dp[i][j];
                if (p.charAt(j) == '*') {
                    if (s.charAt(i) != p.charAt(j - 1) && p.charAt(j - 1) != '.')
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    else {
                        //res[i + 1][j - 1] 表示*一个都不匹配;
                        //res[i + 1][j]表示匹配一个
                        //res[i][j + 1]表示匹配多个
                        dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i + 1][j] || dp[i][j + 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
}
