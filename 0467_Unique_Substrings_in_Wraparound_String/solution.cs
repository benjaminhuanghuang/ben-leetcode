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