package cn.huang.leetcode;

/*
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false


 */
public class LC_0044_WildcardMatching {
    /*
    https://www.youtube.com/watch?v=-8QnRMyHo_o
     */
    public boolean isMatch(String s, String p) {
        int sp = 0;
        int pp = 0;
        int match = 0;
        int start = -1;
        while (sp < s.length()) {
            if (pp < p.length() && (s.charAt(sp) == p.charAt(pp) || p.charAt(pp) == '?')) {
                sp++;
                pp++;
            } else if (pp < p.length() && p.charAt(pp) == '*') {
                start = pp;
                match = sp;
                pp++;
            } else if (start != -1) {
                pp = start + 1;
                match++;
                sp = match;
            } else
                return false;
        }
        while (pp < p.length() && p.charAt(pp) == '*') {
            pp++;
        }
        return pp == p.length();
    }
}
