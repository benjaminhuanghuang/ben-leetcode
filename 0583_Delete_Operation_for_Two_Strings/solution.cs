using System;

public class Solution583
{
    /*
    dp[x][y] = x + y     if x == 0 or y == 0

    dp[x][y] = dp[x - 1][y - 1]     if word1[x] == word2[y]

    dp[x][y] = min(dp[x - 1][y], dp[x][y - 1]) + 1     otherwise
     */
    public int MinDistance(string word1, string word2)
    {
        if (word1 == null && word2 == null)
            return 0;
        if (word1.Length == 0 && word2.Length == 0)
            return 0;
        if (word1 == null || word1.Length == 0)
            return word2.Length;
        if (word2 == null || word2.Length == 0)
            return word1.Length;

        int len1 = word1.Length;
        int len2 = word2.Length;
        int[,] dp = new int[len1+1, len2+1];
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
                if( i ==0 || j==0)
                {
                    dp[i,j] = i+j;
                }
                else if(word1[i - 1] == word2[j - 1])
                {
                    //word1[x] == word2[y]
                    dp[i,j] = dp[i - 1, j - 1];
                }
                else
                {
                     dp[i,j] = Math.Min(dp[i - 1, j], dp[i,j - 1]) + 1;
                }
            }
        }
        return dp[len1, len2];
    }
}