package cn.huang.leetcode;

/*
	125	 Valid Palindrome

    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Note: For the purpose of this problem, we define empty string as valid palindrome.
*/
public class LC_0125_ValidPalindrome {
    public boolean isPalindrome_Better(String s) {
        if (s == null || s.length() == 0)
            return true;
        int i = 0;
        int j = s.length() - 1;
        s = s.toLowerCase();

        while (i < j) {
            if (!Character.isLetterOrDigit(s.charAt(i))) {
                i++;
                continue;
            }
            if (!Character.isLetterOrDigit(s.charAt(j))) {
                j--;
                continue;
            }
            if (s.charAt(i) == s.charAt(j)) {
                i++;
                j--;
            } else
                return false;
        }
        return true;
    }

    public boolean isPalindrome_Faster(String s) {
        if (s.length() == 0)
            return true;

        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (!isAlpha(s.charAt(l)) && !isNum(s.charAt(l))) {
                l++;
            }

            if (!isAlpha(s.charAt(r)) && !isNum(s.charAt(r))) {
                r--;
            }

            char left = s.charAt(l);
            char right = s.charAt(r);

            if (!isSame(left, right)) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    private boolean isAlpha(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }

    public boolean isNum(char a) {
        return a >= '0' && a <= '9';
    }

    public boolean isSame(char a, char b) {
        if (isNum(a) && isNum(b)) {
            return a == b;
        }

        return Character.toLowerCase(a) == Character.toLowerCase(b);
    }
}
