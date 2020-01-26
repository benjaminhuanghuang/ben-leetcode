/*
242. Valid Anagram

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
using System.Linq;

public class Solution242 {
    public bool IsAnagram(string s, string t) {
        if (s.Length != t.Length) return false;
        var seen = new int[256];

        for (int i = 0; i < s.Length; i++)         
        {             
            seen[s[i]]++;             
            seen[t[i]]--;         
        }         
        return seen.All(x => x == 0);     
    }

    // Method 2 , sort and compare
    // Method 3, Hashtable
}

