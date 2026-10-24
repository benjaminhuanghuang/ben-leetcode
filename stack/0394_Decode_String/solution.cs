/*
394. Decode String

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
using System.Text;
using System.Collections.Generic;

public class Solution394 {
    public string DecodeString(string s) {
        string res = "";
        var counts = new Stack<int>();
        var strs = new Stack<string>();
        
        int i = 0;
        while( i < s.Length)
        {
            if(char.IsDigit(s[i]))
            {
                int num=0;
                while(char.IsDigit(s[i])){
                    num = num * 10 + (s[i]-'0');
                    i++;
                }
                counts.Push(num);
            }
            else if(s[i]=='[')
            {
                strs.Push(res);
                res="";
                i++;
            }
            else if (s[i]==']')
            {
                StringBuilder sb = new StringBuilder(strs.Pop());
                int count = counts.Pop();
                for(int j=0; j< count ; j++){
                    sb.Append(res);
                }
                res = sb.ToString();
                i++;
            }
            else   // normal char
            {   
                res += s[i++];
            }
        }
        return res;
    }
}