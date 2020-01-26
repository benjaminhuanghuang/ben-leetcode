/*
467. Unique Substrings in Wraparound String

Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", 
so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p 
are present in s. In particular, your input is the string p and you need to output the number of 
different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the 
string s.
 */

/**
     * 其实就是找出P中有多少个子串，子串能够在abcdedf...zabcdefg...zab...这样的一个子串里面找到
     * 也就是递增的过程
     * 考虑为一个26进制的数的序列
     * 使用dp的方式，找到以某个字符结尾的最长的有多少种可能
     * */
using System;

public class Solution467
{
    public int FindSubstringInWraproundString(string p)
    {
        int[] p_int = new int[p.Length];
        int[] count = new int[26];
        for (int i = 0; i < p.Length; i++)
        {
            p_int[i] = p[i] - 'a';
        }

        int res = 0;
        int maxLen = 0;
        for (int i = 0; i < p.Length; i++)
        {
            if (i > 0 && (p_int[i - 1] + 1) % 26 == p_int[i])
            {
                maxLen++;
            }
            else
            {
                maxLen = 1;
            }
            count[p_int[i]] = Math.Max(count[p_int[i]], maxLen);
        }
        for (int i = 0; i < 26; i++)
            res += count[i];
        return res;

    }
}