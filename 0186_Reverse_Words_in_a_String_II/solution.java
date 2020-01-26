package cn.huang.leetcode;
/*
186. Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence
of non-space characters.

The input string does not contain leading or trailing spaces and the words are always
separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
 */
public class LC_0186_ReverseWordsinaString_II {

    public void reverseWords(char[] s)
    {
        int i = 0;
        for (int j = 0; j < s.length; j++)
        {
            if (s[j] == ' ')
            {
                reverseBetween(s, i, j - 1);
                i = j + 1;
            }
        }
        reverseBetween(s, 0, s.length - 1);
    }

    public void reverseBetween(char[] s, int i, int j)
    {
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
}
