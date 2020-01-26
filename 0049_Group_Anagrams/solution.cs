/*
49. Group Anagrams

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution049 {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var dict = new Dictionary<string, List<string>>();

        foreach (var str in strs)
        {
            char[] cs = str.ToCharArray();
            Array.Sort(cs);
            var strsorted = new String(cs);
            if (dict.ContainsKey(strsorted))
            {
                dict[strsorted].Add(str);
            }
            else
            {
                dict.Add(strsorted, new List<string>(){str});
            }
        }

        return dict.Select(one => one.Value).Cast<IList<string>>().ToList();
    }
}