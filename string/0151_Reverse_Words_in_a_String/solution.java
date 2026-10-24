package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Collections;

/*
151. Reverse Words in a String

Given an input string, reverse the string word by word.

Example:

Input: "the sky is blue",
Output: "blue is sky the".


Note:

    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.

Follow up: For C programmers, try to solve it in-place in O(1) space.
 */
public class LC_0151_ReverseWordsinaString {
    /*
    Can not pass the test:
    Input "   a   b "
    Output "b   a"
    Expected "b a"
     */
    public String reverseWords(String s) {
        s = s.trim(); //your reversed string should not contain leading or trailing spaces.
        if (s == null || s.length() == 0) {
            return s;
        }

        char[] charArray = s.toCharArray();

        for (int i = s.length() - 1; i >= 0; i--) {
            if (charArray[i] == ' ') {
                continue;
            }

            int end = i;
            while (i >= 0 && charArray[i] != ' ') {
                i--;
            }

            int start = i;
            swap(charArray, start + 1, end);
        }
        swap(charArray, 0, s.length() - 1);

        return String.valueOf(charArray);
    }

    public void swap(char[] s, int start, int end) {
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }


    public String reverseWords_Easy(String s) {
        String res = "";
        String[] words = s.trim().split("\\s+");
        for (int i = words.length - 1; i > 0; --i) {
            res += words[i] + " ";
        }
        return res + words[0];
    }

    public String reverseWords_Easy2(String s) {
        String[] words = s.trim().split(" +");
        Collections.reverse(Arrays.asList(words));
        return String.join(" ", words);
    }
}
