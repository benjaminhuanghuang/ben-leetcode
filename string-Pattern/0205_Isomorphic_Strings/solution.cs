/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order 
of characters. 
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/
using System;
using System.Text;
using System.Collections.Generic;

public class Solution205 {
    public bool IsIsomorphic(string s, string t) {
        if (s.Length != t.Length)
            return false;

        Dictionary<char, char> stMap = new Dictionary<char, char>();
        Dictionary<char, char> tsMap = new Dictionary<char, char>();

        for (int i =0; i < s.Length; i++)
        {
            if(!stMap.ContainsKey(s[i]))
            {
                stMap.Add(s[i], t[i]);
            }
            else
            {
                if(stMap[s[i]] != t[i])
                    return false;
            }
            if(!tsMap.ContainsKey(t[i]))
            {
                tsMap.Add(t[i], s[i]);
            }
            else
            {
                if(tsMap[t[i]] != s[i])
                    return false;
            }

        }
        return true;
    }

    public bool isomorphic2(string str1, string str2)
    {
        if (str1.Length != str2.Length)
        {
            return false;
        }

        var strDictionary = new Dictionary<char, char>();
        var length = str1.Length;
        var stringbuilder1 = new StringBuilder();
        var stringbuilder2 = new StringBuilder();

        for (int i = 0; i < length; i++)
        {
            if (strDictionary.ContainsKey(str1[i]))
            {
                stringbuilder1.Append(strDictionary[str1[i]]);
            }
            else
            {
                strDictionary.Add(str1[i], Convert.ToChar(i));
                stringbuilder1.Append(Convert.ToChar(i));
            }
        }

        strDictionary.Clear();
        for (int i = 0; i < length; i++)
        {
            if (strDictionary.ContainsKey(str2[i]))
            {
                stringbuilder2.Append(strDictionary[str2[i]]);
            }
            else
            {
                strDictionary.Add(str2[i], Convert.ToChar(i));
                stringbuilder2.Append(Convert.ToChar(i));
            }
        }

        return stringbuilder1.ToString() == stringbuilder2.ToString();
    }
}