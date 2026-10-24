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
