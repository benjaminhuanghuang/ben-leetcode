/*
387. First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

using System.Collections.Generic;

public class Solution387 {
    public int FirstUniqChar(string s) {
        var charDic = new Dictionary<char, int>();
        foreach(char c in s)
        {
            if (charDic.ContainsKey(c))
            {
                charDic[c]++;
            }
            else
            {
                charDic.Add(c, 1);
            }
        }
        for(int i =0; i< s.Length; i++)
        {
            if (charDic[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
}