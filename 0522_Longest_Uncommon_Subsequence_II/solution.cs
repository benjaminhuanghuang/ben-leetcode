/*
522. Longest Uncommon Subsequence II

Given a list of strings, you need to find the longest uncommon subsequence among them. The longest 
uncommon subsequence is defined as the longest subsequence of one of these strings and this 
subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters 
without changing the order of the remaining elements. Trivially, any string is a subsequence of 
itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon 
subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].

 */
using System;
using System.Collections.Generic;

public class Solution522
{
    public int FindLUSlength(string[] strs)
    {
        Dictionary<string, int> subseqFreq = new Dictionary<string, int>();
        foreach (string s in strs)
            foreach (string subSeq in getSubseqs(s))
                if (!subseqFreq.ContainsKey(subSeq))
                    subseqFreq[subSeq] = 1;
                else
                    subseqFreq[subSeq]++;
        int longest = -1;
        foreach (KeyValuePair<string, int> element in subseqFreq)
            if (element.Value == 1)
                longest = Math.Max(longest, element.Key.Length);
        return longest;
    }

    private HashSet<string> getSubseqs(String s)
    {
        HashSet<string> res = new HashSet<string>();
        if (s.Length == 0)
        {
            res.Add("");
            return res;
        }
        HashSet<string> subRes = getSubseqs(s.Substring(1));
        res.UnionWith(subRes);
        foreach (string seq in subRes)
            res.Add(s[0] + seq);
        return res;
    }
}

/*
    string[] input = new string[]{"aba", "cdc", "eae"};
    var s = new Solution522();
    Console.WriteLine(s.FindLUSlength(input));

 */
