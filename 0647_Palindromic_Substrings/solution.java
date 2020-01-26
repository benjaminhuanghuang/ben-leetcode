package cn.huang.leetcode;

/*
647. Palindromic Substrings

 */
public class LC_0647_PalindromicSubstrings {
    public int countSubString(String str) {
        int count = 0;
        int i = 0;
        while (i++ < str.length()) {
            count++;
        }
        for (int j = 2; j <= str.length(); j++) {
            for (int x = 0; x + j <= str.length(); x++) {
                if (isPalindrome(str.substring(x, x + j))) {
                    count++;
                }
            }
        }
        return count;
    }

    public boolean isPalindrome(String subStr) {
        for (int i = 0; i < subStr.length(); i++) {
            if (subStr.charAt(i) != subStr.charAt(subStr.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
    // DP
    public int countSubstrings_2(String s) {
        int count = 0;
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (i == j || (s.charAt(i) == s.charAt(j) && (isPalindrome[i + 1][j - 1] || j - i == 1))) {
                    isPalindrome[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
}
