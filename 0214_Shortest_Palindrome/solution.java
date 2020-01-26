package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Collections;

/*
214. Shortest Palindrome

Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it.
Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"

Example 2:

Input: "abcd"
Output: "dcbabcd"
 */
public class LC_0214_ShortestPalindrome {
    public String shortestPalindrome(String s) {
        char[] array = s.toCharArray();
        reverse(array);
        for (int i = 0; i < array.length; i++) {
            String right = new String(array, i, s.length() - i);

            if (s.startsWith(right)) {
                String padding = new String(array, 0, i);
                return padding + s;
            }
        }
        return "";
    }

    private void reverse(char[] data) {
        for (int left = 0, right = data.length - 1; left < right; left++, right--) {
            // swap the values at the left and right indices
            char temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
    }

    /*
    https://www.youtube.com/watch?v=aQ-Y51n6SD0
     */
    public String shortestPalindrome_better(String s) {
        int i = 0;
        int j = s.length() - 1;
        int end = s.length() - 1;

        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;
                j--;
            } else {
                i = 0;
                end--;
                j = end;
            }
        }
        return new StringBuilder(s.substring(end + 1)).reverse().toString() + s;
    }
}
