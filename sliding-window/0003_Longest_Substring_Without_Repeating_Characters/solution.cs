/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
using System;
using System.Collections.Generic;

public class Solution003 {
    // http://www.jiuzhang.com/solutions/longest-substring-without-repeating-characters/
    // https://miafish.wordpress.com/2015/01/22/leetcode-oj-c-longest-substring-without-repeating-characters/
    public int LengthOfLongestSubstring(string s) {
        int answer = 0;
        int left = 0; // left is the next index of repeating char.
        Dictionary<char, int > lastCharPos = new Dictionary<char, int>();
        for(int i =0;i< s.Length; i ++)
        {
            if (lastCharPos.ContainsKey(s[i]))
            {
                // test case: "abba"
                // sub string starts from left.  
                left = Math.Max(left, lastCharPos[s[i]] +1);
                lastCharPos[s[i]] = i;
            }
            else
            {
                lastCharPos.Add(s[i],i);
            }
            answer = Math.Max(answer,  i - left + 1);
        }    
        return answer;
    }
}

