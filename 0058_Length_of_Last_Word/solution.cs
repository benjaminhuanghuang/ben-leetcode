/*
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
using System;

public class Solution058 {

    public int lengthOfLastWord(String s)
    {
        if (string.IsNullOrEmpty(s))
        {
            return 0;
        }

        var trimed = s.TrimEnd();

        int i;
        for (i = trimed.Length - 1; i >= 0; i--)
        {
            if (trimed[i] == ' ')
            {
                return trimed.Length - 1 - i;
            }
        }

        return trimed.Length - 1 - i >= 0 ? trimed.Length - 1 - i : 0;
    }

    public int LengthOfLastWord(string s) {
        if (string.IsNullOrEmpty(s)) 
            return 0;
        s = s.TrimEnd();
        var index = s.LastIndexOf(' ');
        return s.Length - 1 - index;
    }
}