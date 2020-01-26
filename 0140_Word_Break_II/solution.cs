/*
139. Word Break II

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word 
is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

*/
using System.Collections.Generic;


public class Solution140 {
    // DP,  instead of store bool for each index, store a list of string. see example as below.
    public IList<string> WordBreak(string s, ISet<string> wordDict) {
        var res = new List<string>();
        var solution = string.Empty;

        var dp = new List<string>[s.Length + 1];
        for (int i = 0; i < s.Length + 1; i++)
        {
            dp[i] = new List<string>();
        }

        for (int i = 0; i < s.Length; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j != 0 && dp[j].Count == 0) continue;

                var substr = s.Substring(j, i - j + 1);
                if (wordDict.Contains(substr))
                {
                    dp[i + 1].Add(substr);
                }
            }
        }

        Helper(dp, s.Length, res, solution);

        return res;
    }
    private void Helper(List<string>[] dp, int index, List<string> res, string solution)
    {
        if (index == 0)
        {
            solution = solution.Remove(solution.Length - 1);
            res.Add(solution);
            return;
        }

        foreach (var list in dp[index])
        {
            solution = list + " " + solution;
            this.Helper(dp, index - list.Length, res, solution);
            solution = solution.Substring(list.Length + 1);
        }
    }
    public IList<string> WordBreak_2(string s, ISet<string> wordDict) {
        return null;
    }

}

