/*
115. Distinct Subsequences

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting 
some (can be none) of the characters without disturbing the relative positions of the remaining 
characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

public class Solution115 {
    public int NumDistinct(string s, string t) {
        var lens = s.Length;
        var lent = t.Length;

        var dp = new int[lens + 1, lent + 1];
        dp[0, 0] = 1;
        for (int i = 0; i < lens; i++)
        {
            dp[i + 1, 0] = 1;
        }

        for (int i = 1; i <= lens; i++)
        {
            for (int j = 1; j <= lent; j++)
            {
                if (s[i - 1].Equals(t[j - 1]))
                {
                    dp[i, j] = dp[i - 1, j - 1] + dp[i - 1, j];
                }
                else
                {
                    dp[i, j] = dp[i - 1, j];
                }
            }
        }

        return dp[lens, lent];
    }
}