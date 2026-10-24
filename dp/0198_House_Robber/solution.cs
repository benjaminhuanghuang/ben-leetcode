/*
198. House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine 
the maximum amount of money you can rob tonight without alerting the police.

Hint:
    http://www.cnblogs.com/grandyang/p/4383632.html
    Pickup one or more numbers in a array. The numbers can not be adjacent. Make the sum of the number biggest.

Sample: for nums [3, 2, 1, 5]
dp[0] = 3
dp[1] = 3  because can not rob room[1]
dp[2] = max (dp[0] + nums[2], dp[1])
...
dp[i] = max (dp[i-2] + nums[i], dp[i-1])

*/
using System;

public class Solution198 {
    public int Rob(int[] nums) {
        if (nums.Length == 0)
            return 0;

        var dp = new int[nums.Length + 1];
        dp[1] = nums[0];
       
        for (int i = 2; i < nums.Length + 1; i++)
        {
            dp[i] = Math.Max(dp[i - 1], dp[i - 2] + nums[i-1]);
        }

        return dp[nums.Length];
    }

    public int Rob_2(int[] nums) {
        int len = nums.Length;
        int odd = 0, even =0;
        for (int i = 0; i < len; i++)
        {   
            if (i % 2 == 0)
                even = Math.Max(odd, even + nums[i]);
            else
                odd = Math.Max(even, odd + nums[i]);
        }

        return Math.Max(odd, even);
    }
}