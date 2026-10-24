/*
97. Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

*/

public class Solution097 {
    // dp[i, j], s1 up to s[i], s2 up to s[j], weather s3 is interleaving of s1 and s2.
    // dp[i][j]表示s1取前i位，s2取前j位，是否能组成s3的前i+j位
    // d[i][j] means s1[0...i-1] and s2[0...j-1] can connect to s3[0...i+j-1]
    // http://blog.csdn.net/u011095253/article/details/9248073
    public bool IsInterleave(string s1, string s2, string s3) {
        var len1 = s1.Length;
        var len2 = s2.Length;
        var len3 = s3.Length;

        if (len3 != len1 + len2)
        {
            return false;
        }

        var dp = new bool[s1.Length + 1, s2.Length + 1];

        dp[0, 0] = true;

        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {                     
                if (i > 0 && s1[i - 1].Equals(s3[i + j - 1]))
                {
                    dp[i, j] |= dp[i - 1, j];
                }

                if (j > 0 && s2[j - 1].Equals(s3[i + j - 1]))
                {
                    dp[i, j] |= dp[i, j - 1];
                }
            }
        }

        return dp[len1, len2];
    }

    public bool IsInterleave_2(string s1, string s2, string s3) {
        var len1 = s1.Length;
        var len2 = s2.Length;
        var len3 = s3.Length;

        if (len3 != len1 + len2)
        {
            return false;
        }

        var dp = new bool[s1.Length + 1, s2.Length + 1];

        dp[0, 0] = true;
        // d[i][j] means s1[0...i-1] and s2[0...j-1] can connect to s3[0...i+j-1]
        for (int i = 1 ; i <= len1; i++)
            dp[i,0] = dp[i-1,0] && s3[i-1] == s1[i-1];
        for (int i = 1 ; i <= len2; i++)
            dp[0,i] = dp[0,i-1] && s3[i-1] == s2[i-1];
        
        for (int i = 1 ; i <= len1; i++)
        {
            for (int j = 1 ; j <= len2; j++)
            {
                dp[i,j] = (dp[i - 1,j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i,j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[len1, len2];
    }
}