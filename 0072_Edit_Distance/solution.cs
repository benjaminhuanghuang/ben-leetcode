/*
72. Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/


using System;

public class Solution072 {
    /*
    we know the numbers before dp[i][j]. such as dp[i -1][j -1], dp[i][j -1] and dp[i -1][j]…

    if word1 at i == word2 at j. OK, just get the dp[i -1][j-1].
    if word1 at i != word2 at j.  let us think about it how many cases we need to think about it.
        we can based on the i – 1, and j – 1. just change the word1 at i to word2 at j.
        we can based on the i and j – 1. just add char word2 at j.
        we can based on the i -1 and j. just delete the char word1 at i.
    OK. it seems easy. and the last thing we need to think about is what we know from beginning. 
    dp[0][0] should be 0. nothing there. dp[i][0] == dp[0][i] = i, just delete or add i chars there. Here is the code.
    */
    public int MinDistance(string word1, string word2) {
        var len1 = word1.Length;
        var len2 = word2.Length;
        var dp = new int[len1 + 1, len2 + 1];
        dp[0, 0] = 0;

        for (int i = 1; i <= len1; i++)
        {
            dp[i, 0] = i;
        }
        for (int i = 1; i <= len2; i++)
        {
            dp[0, i] = i;
        }

        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (word1[i].Equals(word2[j]))
                {
                    dp[i + 1, j + 1] = dp[i, j];
                }
                else
                {
                    dp[i + 1, j + 1] = Math.Min(Math.Min(dp[i, j], dp[i, j + 1]), dp[i + 1, j]) + 1;
                }
            }
        }

        return dp[len1, len2];
    }
}