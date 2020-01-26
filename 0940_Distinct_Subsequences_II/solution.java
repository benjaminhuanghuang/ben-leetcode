package cn.huang.leetcode;

import java.util.Arrays;

/*
940. Distinct Subsequences II

Given a string S, moves the number of distinct, non-empty subsequences of S .

Since the result may be large, return the answer modulo 10^9 + 7.

Example 1:

Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

Example 2:

Input: "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".

Example 3:

Input: "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".



Note:

    S contains only lowercase letters.
    1 <= S.length <= 2000

 */
public class LC_0940_DistinctSubsequences_II {
    /*
    https://www.jianshu.com/p/02501f516437
     */
    public int distinctSubseqII(String S) {
        int end[] = new int[26], res = 0, added = 0, mod = (int) 1e9 + 7;
        for (char c : S.toCharArray()) {
            added = (res + 1 - end[c - 'a']) % mod;
            res = (res + added) % mod;
            end[c - 'a'] = (end[c - 'a'] + added) % mod;
        }
        return (res + mod) % mod;
    }
}
