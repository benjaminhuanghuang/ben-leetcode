/*
343. Integer Break

Given a positive integer n, break it into the sum of at least two positive integers and maximize the 
product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.


https://www.hrwhisper.me/leetcode-integer-break/

*/
using System;

public class Solution343 {
    // 设dp[i]为最大的乘积值
    public int IntegerBreak_Wrong(int n) {
        int[] dp = new int[n+1];
        for (int i=0; i < n+1; i++)
            dp[i] = 1;

        for (int i=0; i < n+1; i++)
        {
            for (int j=0; j < i+1; j++)
                if (i + j <= n)
                    dp[i + j] = Math.Max(Math.Max(dp[i],i) * Math.Max(dp[j],j), dp[i + j]);
        }
        return dp[n];
    }
    // 在n >3的情况下，我们处理一个数拆分成2，要么拆分成3，（4的话相当于2个2 ， 拆成1的话乘积太小了
     public int IntegerBreak_2(int n) {
        if (n <= 3)
            return n - 1;

        int[] dp = new int[n+1];
        for (int i=0; i < n+1; i++)
            dp[i] = 1;

        dp[2] = 2;
        dp[3] = 3;
        for(int i =4; i< n + 1; i++)
            dp[i] = Math.Max(dp[i - 2] * 2, dp[i - 3] * 3);
        return dp[n];

     }
}

