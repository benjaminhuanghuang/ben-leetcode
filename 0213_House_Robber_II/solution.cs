/*
213. House Robber II

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that 
he will not get too much attention. This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses 
remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum 
amount of money you can rob tonight without alerting the police.

*/
using System;

public class Solution213 {
    // 把第一家和最后一家分别去掉，各算一遍能抢的最大值，然后比较两个值取其中较大的一个即为所求。
    public int Rob(int[] nums) {
        if(nums.Length == 1)
            return nums[0];
        // skip first one;
        int max1 = this.MaxRob(nums, 1, nums.Length -1);
        // skip last one
        int max2 = this.MaxRob(nums, 0, nums.Length -2);

        return Math.Max(max1, max2);
    }

    public int MaxRob(int[] nums, int start, int end)
    {
        int count = 1;
        int sumOdd = 0;
        int sumEven = 0;
        for(int i = start; i <= end; i++, count++)
        {
            if(count %2 ==1)
                sumOdd = Math.Max(sumOdd + nums[i], sumEven);
            if(count %2 ==0)
                sumEven = Math.Max(sumEven + nums[i], sumOdd);
        }
        return Math.Max(sumOdd, sumEven);
    }

    // dp[i, j, k]: i is the house number, j means it robbed or not, k indicates the first house got robbed or not.
    public int Rob_2(int[] nums)
    {
        if (nums.Length == 0) return 0;
        if (nums.Length == 1) return nums[0];
        var dp = new int[nums.Length, 2, 2];

        dp[0, 1, 1] = nums[0];
        dp[0, 1, 0] = 0;
        dp[0, 0, 0] = 0;
        dp[0, 0, 1] = 0;

        for (int i = 1; i < nums.Length; i++)
        {
            dp[i, 0, 1] = Math.Max(dp[i - 1, 0, 1], dp[i - 1, 1, 1]);
            dp[i, 1, 1] = dp[i - 1, 0, 1] + nums[i];

            dp[i, 0, 0] = Math.Max(dp[i - 1, 0, 0], dp[i - 1, 1, 0]);
            dp[i, 1, 0] = dp[i - 1, 0, 0] + nums[i];
        }

        return Math.Max(Math.Max(dp[nums.Length - 1, 1, 0], dp[nums.Length - 1, 0, 1]), dp[nums.Length - 1, 0, 0]);
    }
}