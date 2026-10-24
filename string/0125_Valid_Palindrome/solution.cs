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