package cn.huang.leetcode;
/*
 Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 */
public class LC_0344_ReverseString {
    public String reverseString(String s) {
        char[] chars = s.toCharArray();

        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            char tmp = chars[r];
            chars[r] = chars[l];
            chars[l] = tmp;
            l++;
            r--;
        }
        return String.valueOf(chars);
    }
}
