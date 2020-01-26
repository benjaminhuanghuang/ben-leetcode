package cn.huang.leetcode;

import java.util.HashSet;
import java.util.Set;

/*
    345	 Reverse Vowels of a String
    Write a function that takes a string as input and reverse only the vowels of a string.

    Example 1:

    Input: "hello"
    Output: "holle"
    Example 2:

    Input: "leetcode"
    Output: "leotcede"
    Note:
    The vowels does not include the letter "y".


 */
public class LC_0345_ReverseVowelsofaString {
    public String reverseVowels(String s) {
        Set<Character> vowels = new HashSet<>();
        for (char c : new char[]{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}) {
            vowels.add(c);
        }

        int l = 0;
        int r = s.length() - 1;
        char[] chars = s.toCharArray();

        while (l < r) {
            if (!vowels.contains(chars[l])) {
                l++;
                continue;
            }
            if (!vowels.contains(chars[r])) {
                r--;
                continue;
            }
            if (l < r) {
                char tmp = chars[r];
                chars[r] = chars[l];
                chars[l] = tmp;
                l++;
                r--;
            }
        }
        return String.valueOf(chars);
    }
}
