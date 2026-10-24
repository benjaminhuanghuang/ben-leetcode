/*
76. Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the 
characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one 
unique minimum window in S.
*/

/*
//https://miafish.wordpress.com/2015/03/13/leetcode-ojc-minimum-window-substring/
Solution : leetcode needs O(n) solution, so we could not use brute force solution. 
1. how to get the first window that contains all the characters of T? use hash table would be easy. 
2. then how do we get the next window or next next window? there is a trick here. Keep adding character 
    that is not the same as the first character to the window until we find one that is equal to first character. 
    delete the first character and continue deleting characters until find some character that is T.
*/

using System.Collections.Generic;

public class Solution076 {
    
    // 双指针思想，尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符，然后再收缩头指针，直到不能再收缩为止。
    // 最后记录所有可能的情况中窗口最小的。
    // 用dict来表示滑窗， 字符加入滑窗，从dict[c] - 1，从滑窗中删去字符，dict[c] +1
    public string MinWindow(string s, string t) {
        //dict for chars in tartget
        //  dic = collections.defaultdict(list)
        var dict = new Dictionary<char, int>();
        for (int i = 0; i < t.Length; i++)
        {
            if (dict.ContainsKey(t[i]))
            {
                dict[t[i]]++;
            }
            else
            {
                dict.Add(t[i], 1);
            }
        }

        var res = string.Empty;
        var resLength = s.Length + 1;
        var start = 0;
        var leftChartCount = t.Length;
        for (int i = 0; i < s.Length; i++)             
        {                 
            if (dict.ContainsKey(s[i]))                 
            {                     
                if (dict[s[i]]> 0) // if s[i] is char in t string
                {
                    leftChartCount--;
                }
                dict[s[i]]--;   //
            }
            // When leftChartCount == 0, substring S[start : i] contains string T     
            while (leftChartCount == 0)
            {
                if (resLength > i - start + 1)   // find res shorter than last res or find res firstly
                {
                    resLength = i - start + 1;
                    res = s.Substring(start, resLength);
                }

                if (dict.ContainsKey(s[start]))
                {
                    if (dict[s[start]] >= 0)   //  remove first char from the sub string
                    {
                        leftChartCount++;
                    }
                    dict[s[start]]++;
                }
                start++;
            }
        }

        return res;
    }
}


// string S = "ADOBECODEBANC";
// string T = "ABB";

// var s = new Solution076();
// var res = s.MinWindow(S, T);

// Console.WriteLine(res);

