package cn.huang.leetcode;

/*
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"


 */
public class LC_0005_LongestPalindromicSubstring {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0)
            return "";
        // dp[i][j] means string[i to j] is palindromic or not
        boolean[][] dp = new boolean[s.length()][s.length()];
        String res = "";
        int maxLen = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j) && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;  // single char is palin
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        res = s.substring(i, j + 1);
                    }
                }
            }
        }
        return res;
    }

    /*
    https://www.youtube.com/watch?v=m2Mk9JN5T4A
    Time O(n^2) , Space O(n^2)
     */
    public String longestPalindrome2(String s) {
        if (s == null || s.length() == 0)
            return "";

        boolean[][] dp = new boolean[s.length()][s.length()];
        String res = "";
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {   // j <= i
                if (s.charAt(i) == s.charAt(j) && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (maxLen < i - j + 1) {
                        maxLen = i - j + 1;
                        res = s.substring(j, i + 1);
                    }
                }
            }
        }
        return res;
    }

    /*
    https://www.youtube.com/watch?v=m2Mk9JN5T4A
    Time O(n^2) , Space O(1)
     */
    String res = "";

    public String longestPalindrome3(String s) {
        if (s == null || s.length() == 0)
            return "";

        for (int i = 0; i < s.length(); i++) {
            helper(s, i, i);
            helper(s, i, i + 1);
        }
        return res;
    }

    private void helper(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        String curr = s.substring(left + 1, right);  //! not (left, right +1)
        if (curr.length() > res.length())
            res = curr;
    }
}
