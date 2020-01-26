/*
583. Delete Operation for Two Strings
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 
the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.

 */

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