/*
316. Remove Duplicate Letters

Given a string which contains only lowercase letters, remove duplicate letters so that every letter 
appear once and only once. You must make sure your result is the smallest in lexicographical order 
among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"


*/
using System.Collections.Generic;
using System.Text;

public class Solution316 {
    // removing all letters to the left of s[i],
    // removing all s[i]'s from s.
    public string RemoveDuplicateLetters(string s) {
        int[] count = new int[26];  
       
        for(int i=0; i<s.Length; i++) 
            count[s[i] - 'a']++;  
        
        int pos = 0;
        for(int i=0; i<s.Length; i++) {  
            if(s[i]< s[pos]) 
                pos = i;  
            if(--count[s[i] - 'a'] == 0) 
                break;  
        }  
        return s.Length == 0? "" : s[pos] + RemoveDuplicateLetters(s.Substring(pos+1).Replace(s[pos].ToString(), ""));  
    }
}