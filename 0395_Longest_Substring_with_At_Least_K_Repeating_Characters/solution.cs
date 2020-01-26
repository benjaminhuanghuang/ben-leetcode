/*
395. Longest Substring with At Least K Repeating Characters

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that 
every character in T appears no less than k times.

Example 1:
    Input:
    s = "aaabb", k = 3

    Output:
    3

    The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
    Input:
    s = "ababbc", k = 2

    Output:
    5

    The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/
using System;
using System.Collections.Generic;

public class Solution395 {
    //http://www.cnblogs.com/grandyang/p/5852352.html
    //求一个最大子字符串并且每个字符必须至少出现k次
    //用哈希表建立了字符和其出现次数之间的映射，但是如果每一次都要遍历哈希表中的所有字符看其出现次数是否大于k，未免有些不高效。
    //整型mask有32位，每一位代表一个字母，如果为1，表示该字母不够k次，如果为0就表示已经出现了k次
    //我们遍历字符串，对于每一个字符，我们都将其视为起点，然后遍历到末尾，我们增加哈希表中字母的出现次数，
    //如果其小于k，我们将mask的对应位改为1，如果大于等于k，将mask对应位改为0。然后看mask是否为0，是的话就更新res结果，
    //然后把当前满足要求的子字符串的起始位置j保存到max_idx中，等内层循环结束后，将外层循环变量i赋值为max_idx+1
    public int LongestSubstring(string s, int k) {
        int res = 0, i = 0, n = s.Length;
        
        while (i + k <= n) {
            int[] m = new int[26];
            int mask = 0, max_idx = i;
            for (int j = i; j < n; ++j) {
                int t = s[j] - 'a';
                ++m[t];
                if (m[t] < k) 
                    mask |= (1 << t);
                else 
                    mask &= (~(1 << t));
                if (mask == 0) {
                    res = Math.Max(res, j - i + 1);
                    max_idx = j;
                }
            }
            i = max_idx + 1;
        }
        return res;
    }
}

/*
var input = "a";
var s= Solution395();
Console.WriteLine(s.LongestSubstring(input, 1));


 */