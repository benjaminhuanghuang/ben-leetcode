using System;
using System.Text;

public class Solution214 {
    // Find the prefix of s in reversed string of s.
    // Time Limit Exceeded 
    public string ShortestPalindrome(string s) {
        char[] array = s.ToCharArray();
        Array.Reverse(array);
        for(int i =0; i< array.Length; i++)
        {
            string right = new string(array, i, s.Length - i);

            if (s.StartsWith(right))
            {
                string padding = new string(array, 0, i);
                return padding + s;
            }
        }
        return "";
    }

    public string shortestPalindrome2(string s) {
        int left = 0; 
        int right = s.Length-1;
    
        while(right >= 0){
            if(s[left] == s[right]){
                left++;
            }
            right--;
        }
    
        if(left == s.Length)
            return s;
    
        string suffix = s.Substring(left);
        char[] array =suffix.ToCharArray();
        Array.Reverse(array);
        string prefix = new string(array);
        string mid = shortestPalindrome2(s.Substring(0, left));
        return prefix+mid+suffix;
    }
}