/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) 
which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

using System;
// http://www.cnblogs.com/grandyang/p/4800552.html
public class Solution279 {
    public int NumSquares(int n) {
        int max = (int) Math.Sqrt(n);
 
        int[] dp = new int[n+1];
        for (int i=0; i< dp.Length; i++)
        {
            dp[i] = int.MaxValue;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=max; j++){
                if(i==j*j){
                    dp[i]=1;
                }else if(i>j*j){
                    dp[i]=Math.Min(dp[i], dp[i-j*j] + 1);
                }
            }
        }
    
        return dp[n];
    }
}