/*
125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and 
ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


*/
using System;

public class Solution125 {
    public bool IsPalindrome(string s) {
        if (string.IsNullOrEmpty(s))
        {
            return true;
        }

        int left = 0;
        int right = s.Length - 1;
        while (left < right)
        {
            while (left < right && !Char.IsLetterOrDigit(s[left]))          
            {                     
                left++;                 
            }                 
            while (right > left && !Char.IsLetterOrDigit(s[right]))
            {
                right--;
            }

            if (left >= right)
            {
                return true;
            }

            if (Char.ToLower(s[left]) != Char.ToLower(s[right]))
            {
                return false;
            }

            left ++;
            right --;
        }

        return true;
    }
}