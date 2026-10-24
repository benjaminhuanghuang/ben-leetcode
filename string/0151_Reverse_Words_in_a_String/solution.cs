/*
151. Reverse Words in a String


For example,
Given s = "the sky is blue",
return "blue is sky the".

For C programmers: Try to solve it in-place in O(1) space.
*/
using System;
using System.Text;

public class Solution151 {
    public string ReverseWords(string s) {
        var words = s.Split(new[]{' '}, StringSplitOptions.RemoveEmptyEntries);
        Array.Reverse(words);
        return string.Join(" ", words);
    }

    public string ReverseWords_2(string s) {
        var sb = new StringBuilder();
        int end = s.Length -1; 
        for(int i = s.Length-1; i >=0; i--)
        {
            if (s[i] == ' ')
                end = i -1;
            else if(i == 0 || s[i-1] == ' ')
            {   
                if (sb.Length > 0)
                    sb.Append(" ");
                sb.Append(s.Substring(i, end - i +1));
            }
        }
        return sb.ToString();
    }
}
