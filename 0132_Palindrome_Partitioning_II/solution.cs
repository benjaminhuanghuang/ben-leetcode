/*
132. Palindrome Partitioning II  

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
using System;
using System.Linq;
using System.Collections;

public class Solution132 {
    // use one dimension array, dp[i] indicates up to ith the minimum number of cut. 
    // then for each i, find min of dp[j] + 1: j to i that is palindrome.
    public int MinCut(string s) {
        var palindrome = new bool[s.Length, s.Length];

        var dp = new int[s.Length];
        dp[0] = 0;

        for (int i = 1; i < s.Length; i++)
        {
            var minCuts = i;
            for (int j = 0; j <= i; j++)
            {
                if (s[i] != s[j])
                {
                    palindrome[j, i] = false;
                    continue;
                }

                if (i == j || j == i - 1)
                {
                    palindrome[j, i] = true;
                }
                else
                {
                    palindrome[j, i] = palindrome[j + 1, i - 1];
                }

                if (palindrome[j, i])
                {
                    minCuts = Math.Min(minCuts, j == 0 ? 0 : dp[j - 1] + 1);
                }
            }

            dp[i] = minCuts;
        }

            return dp[s.Length - 1];
    }

    //  https://leetcode.com/discuss/9476/solution-does-not-need-table-palindrome-right-uses-only-space
    // Space comlexity is O(N)
    public int MinCut2(string s)
    {
        var cut = Enumerable.Range(-1, s.Length + 1).ToList();
        for (int i = 0; i < s.Length; i++)             
        {                 
            for (int m = i, n = i; m >= 0 && n < s.Length && s[m] == s[n]; m--, n++)                 
            {                     
                cut[n + 1] = Math.Min(cut[n + 1], cut[m] + 1);                 
            }                 
            for (int m = i, n = i + 1; m >= 0 && n < s.Length && s[m] == s[n]; m--, n++)
            {
                cut[n + 1] = Math.Min(cut[n + 1], cut[m] + 1);
            }    
        }

        return cut[s.Length];
    }
}