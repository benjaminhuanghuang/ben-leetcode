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