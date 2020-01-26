/*
44. Wildcard Matching

*/

public class Solution044 {
    public bool IsMatch(string s, string p) {
         return IsMatchRecursion(s, 0, p, 0);
    }
    // But... Time Limit Exceeded!
    private bool IsMatchRecursion(string s, int sindex, string p, int pindex)
    {
        while (sindex >= s.Length && pindex < p.Length && p[pindex] == '*')             
        {                 
            pindex++;             
        }             
        if (sindex >= s.Length && pindex >= p.Length)
        {
            return true;
        }

        if (sindex >= s.Length || pindex >= p.Length)
        {
            return false;
        }
        if (p[pindex] == '*')
        {
            return IsMatchRecursion(s, sindex + 1, p, pindex) || IsMatchRecursion(s, sindex, p, pindex + 1);
        }

        if (p[pindex] == '?' || p[pindex] == s[sindex])
        {
            return IsMatchRecursion(s, sindex + 1, p, pindex + 1);
        }

        return false;
    }

    //dp[i][j] = dp[i – 1][j – 1]  if(s[i] == p[j] || p[j] == ‘?’)
    //dp[i][j] = dp[i – 1][j] || dp[i][j – 1]  if(p[j] == ‘*’)
    public bool IsMatch_DP(string s, string p) {
        var dp = new bool[s.Length + 1, p.Length + 1];
        dp[0, 0] = true;

        for (int j = 0; j < p.Length; j++)
        {
            if (p[j] == '*')
            {
                dp[0, j + 1] = dp[0, j];
            }
        }

        for (int i = 0; i < s.Length; i++)
        {
            for (int j = 0; j < p.Length; j++)
            {
                if (s[i] == p[j])
                {
                    dp[i + 1, j + 1] = dp[i, j];
                }
                else
                {
                    if (p[j] == '?')
                    {
                        dp[i + 1, j + 1] = dp[i, j];
                    }
                    else if (p[j] == '*')
                    {
                        dp[i + 1, j + 1] = dp[i + 1, j] || dp[i, j + 1];
                    }
                    else
                    {
                        dp[i + 1, j + 1] = false;
                    }
                }
            }
        }

        return dp[s.Length, p.Length];      
    }
}