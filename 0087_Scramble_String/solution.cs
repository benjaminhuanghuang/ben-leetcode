using System;
using System.Linq;

public class Solution087 {
    public bool IsScramble_Recursion(string s1, string s2) {
        if (s1.Equals(s2))
        {
            return true;
        }

        var s1Array = s1.ToCharArray();
        var s2Array = s2.ToCharArray();
        Array.Sort(s1Array);
        Array.Sort(s2Array);

        if (!s1Array.SequenceEqual(s2Array))
        {
            return false;
        }

        for (int i = 1; i < s1.Length; i++)
        {
            // [0:i] and [i:]    
            if (IsScramble_Recursion(s1.Substring(0, i), s2.Substring(0, i)) && IsScramble_Recursion(s1.Substring(i), s2.Substring(i))) 
                return true;
            //  [0:i] and [n-i:]    
            if (IsScramble_Recursion(s1.Substring(0, i), s2.Substring(s2.Length - i)) && IsScramble_Recursion(s1.Substring(i), s2.Substring(0, s2.Length - i))) 
                return true;
        }

        return false;
    }

    //  dp[i, j, k] indicates the start index i in S1, j in S2 and length = k is scramble string or not.
    public bool IsScramble_DP(string s1, string s2) {
        var len = s1.Length;

        var dp = new bool[len, len, len + 1];

        for (int length = 1; length <= len; length++)
        {
            for (int i = 0; i + length <= len; i++)
            {
                for (int j = 0; j + length <= len; j++)
                {
                    if (length == 1)
                    {
                        dp[i, j, length] = s1[i] == s2[j];
                    }
                    else
                    {
                        for (int k = 1; k < length; k++)
                        {
                            dp[i, j, length] = dp[i, j, length] ||
                                (dp[i, j + (length - k), k] && dp[i + k, j, length - k]) ||
                                (dp[i, j, k] && dp[i + k, j + k, length - k]);
                        }
                    }
                }
            }
        }

        return dp[0, 0, len];        
    }
}


