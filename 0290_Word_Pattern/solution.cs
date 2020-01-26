/*
290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

using System.Collections.Generic;

public class Solution290 {
    public bool WordPattern(string pattern, string str) {
        var dict = new Dictionary<char, string>();
        var dict2 = new Dictionary<string, char>();
        
        string[] sections = str.Split(' ');
        if (sections.Length != pattern.Length)
            return false;

        for(int i=0; i< pattern.Length; i++)
        {
            if(!dict.ContainsKey(pattern[i]))
            {
                dict.Add(pattern[i], sections[i]);
            }
            else
            {
                if(dict[pattern[i]] !=sections[i])
                    return false;
            }
            if(!dict2.ContainsKey(sections[i]))
            {
                dict2.Add(sections[i],pattern[i]);
            }
            else
            {
                if(dict2[sections[i]] !=pattern[i])
                    return false;
            }
        }
        return true;
    }
}