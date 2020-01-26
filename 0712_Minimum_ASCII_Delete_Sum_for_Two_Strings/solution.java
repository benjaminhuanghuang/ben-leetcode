package cn.huang.leetcode;
/*
712. Minimum ASCII Delete Sum for Two Strings

Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Note:
0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
 */
public class LC_0712_MinimumASCIIDeleteSumforTwoStrings {
    public int minimumDeleteSum(String s1, String s2) {
        if(s1.length()==0)
            return ascii(s2);
        if(s2.length()==0)
            return ascii(s1);
        if(s1.charAt(0)==s2.charAt(0)){
            return minimumDeleteSum(s1.substring(1), s2.substring(1));
        } else {
            return Math.min(minimumDeleteSum(s1, s2.substring(1))+ascii(s2.substring(0,1)),minimumDeleteSum(s1.substring(1), s2)+ascii(s1.substring(0,1)));
        }
    }

    private int ascii(String s){
        int res = 0;
        for(int i=0; i<s.length(); i++){
            res += (int)s.charAt(i);
        }
        return res;
    }

    /*
    dp[i][j] stands for the minimum delete sum of s1[0,i-1] and s2[0,j-1]
    dp[i][j] =
              dp[i-1][j-1]                               //s1[i-1]==s2[j-1]
              dp[i-1][j-1]+ascii(s1[i])+ascii(s2[j])     //s1[i-1]!=s2[j-1]
           or dp[i-1][j]+ascii(s1[i])
           or dp[i][j-1]+ascii(s2[j])
     */
    public int minimumDeleteSum2(String s1, String s2) {
        int[][] dp = new int[s1.length()+1][s2.length()+1];
        for(int i=1; i<=s1.length(); i++){
            dp[i][0] = dp[i-1][0] + s1.charAt(i-1);
        }
        for(int j=1; j<=s2.length(); j++){
            dp[0][j] = dp[0][j-1] + s2.charAt(j-1);
        }
        for(int i=1; i<=s1.length(); i++){
            for(int j=1; j<=s2.length(); j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int count1 = (int)s1.charAt(i-1);
                    int count2 = (int)s2.charAt(j-1);
                    dp[i][j] = Math.min(dp[i-1][j]+count1, dp[i][j-1]+count2);
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]+count1+count2);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
}
