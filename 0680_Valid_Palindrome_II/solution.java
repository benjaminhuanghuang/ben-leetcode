package cn.huang.leetcode;

/*
    680. Valid Palindrome II
    Given a non-empty string s, you may delete at most one character.
     Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

 */
public class LC_0680_ValidPalindrome_II {
    /*
    https://www.youtube.com/watch?v=hvI-rJyG4ik
     */
    public boolean validPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right))
                return isValid(s, left, right - 1) || isValid(s, left + 1, right);
            ++left;
            --right;
        }
        return true;
    }

    boolean isValid(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
}