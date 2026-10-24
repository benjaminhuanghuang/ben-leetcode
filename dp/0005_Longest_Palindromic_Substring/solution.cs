/*
5. Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S 
is 1000, and there exists one unique longest palindromic substring.

*/

public class Solution005 {
    public string LongestPalindrome(string s) {
        string result = "";
        for (int i =0 ;i< s.Length; i++)
        {
            // For case "bab", find palindrome string from "a"
            string sub = this.GetPalindromeSubstring(s, i, i);
            if (result.Length < sub.Length)
            {
                result = sub;
            }
            // For case "baab", find palindrome string from "aa"
            sub = this.GetPalindromeSubstring(s, i, i+1);
            if (result.Length < sub.Length)
            {
                result = sub;
            }
        }
        return result;
    }

    public string GetPalindromeSubstring(string s, int left, int right)
    {
        while(left >=0 && right <s.Length && s[left] == s[right])
        {
            left --;
            right ++;
        }
        // Be careful for the index
        return s.Substring(left+1, right-left-1);
    }
}