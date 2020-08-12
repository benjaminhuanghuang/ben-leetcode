package cn.huang.leetcode;

/*
76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:

    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.


 */

/*
    // Sliding window，尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符，然后再收缩头指针，直到不能再收缩为止。
    // 最后记录所有可能的情况中窗口最小的。
    // 用dict来表示滑窗， 字符加入滑窗，从dict[c] - 1，从滑窗中删去字符，dict[c] +1

 */
public class LC_0076_MinimumWindowSubstring {
    /*
     * https://www.youtube.com/watch?v=dzdtzymjM7A
     */
    public String minWindow(String s, String t) {
        if (s.length() < t.length())
            return "";

        // distince char -> frequency
        int[] dict = new int[128];
        for (char c : t.toCharArray()) {
            dict[c]++;
        }

        int start = 0;
        int restChartCount = t.length();
        int min = Integer.MAX_VALUE;
        String res = "";

        for (int i = 0; i < s.length(); i++) {
            if (dict[s.charAt(i)] > 0) {
                // if s[i] is char in t string
                restChartCount--;
            }
            dict[s.charAt(i)]--; // 在s中且不在t中的的字符的count会变为负值

            while (restChartCount == 0) // When restChartCount == 0, substring S[start : i] contains string T
            {
                if (min > i - start + 1) // find res shorter than last res or find res firstly
                {
                    min = i - start + 1;
                    res = s.substring(start, start + min);
                }

                if (++dict[s.charAt(start)] > 0) {
                    // ++dict[s.charAt(start)] > 0 说明这是t中的字符，
                    // remove first char from the sub string
                    restChartCount++;
                }
                start++;

            }
        }
        return res;
    }

    /*
     * https://www.youtube.com/watch?v=9qFR2WQGqkU&t=1195s
     */
    public String minWindow2(String s, String t) {
        if (s.length() < t.length())
            return "";

        // distince char -> frequency
        int[] dict = new int[128];
        for (char c : t.toCharArray()) {
            dict[c]++;
        }

        int slow = 0;
        int minLen = Integer.MAX_VALUE;
        int matchCount = 0;
        String res = "";

        for (int fast = 0; fast < s.length(); fast++) {
            if (dict[s.charAt(fast)] == 0) {
                continue;
            }
            dict[s.charAt(i)]--; // 在s中且不在t中的的字符的count会变为负值

            while (restChartCount == 0) // When restChartCount == 0, substring S[start : i] contains string T
            {
                if (min > i - start + 1) // find res shorter than last res or find res firstly
                {
                    min = i - start + 1;
                    res = s.substring(start, start + min);
                }

                if (++dict[s.charAt(start)] > 0) {
                    // ++dict[s.charAt(start)] > 0 说明这是t中的字符，
                    // remove first char from the sub string
                    restChartCount++;
                }
                start++;

            }
        }
        return res;
    }
}
