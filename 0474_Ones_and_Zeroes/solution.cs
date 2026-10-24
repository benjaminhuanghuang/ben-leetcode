using System;
public class Solution474
{
    public int FindMaxForm(string[] strs, int m, int n)
    {
        int[,] dp = new int[m + 1, n + 1];
        int ans = dp[0, 0] = 0;
        foreach (string s in strs)
        {
            int zero = 0, one = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '0')
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
            for (int i = m; i > zero - 1; i--)
            {
                for (int j = n; j > one - 1; j--)
                {
                    dp[i, j] = Math.Max(dp[i, j], dp[i - zero, j - one] + 1);
                }
            }
        }
        return dp[m, n];
    }
}