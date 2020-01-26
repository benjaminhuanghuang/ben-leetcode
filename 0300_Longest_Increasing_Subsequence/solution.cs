/*
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

//http://www.cnblogs.com/grandyang/p/4938187.html
// https://www.zhihu.com/question/23995189
using System;
using System.Collections.Generic;

public class Solution300 {
    // https://xuanwo.org/2015/07/31/dp-lis/
    // dp[x] = max(dp[x], dp[y] + 1) y < x and nums[x] > nums[y]
    public int LengthOfLIS_N2(int[] nums) {
        int[] dp = new int[nums.Length];
        for (int i = 0 ; i< nums.Length; i++)
            dp[i] = 1;

        int res = 0;
        for (int i = 0; i < nums.Length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    //只有当a[i]>a[j]的时候，我们需要进行判断，是否将a[i]加入到dp[j]当中。
                    dp[i] = Math.Max(dp[i], dp[j] + 1);
                }
            }
            res = Math.Max(res, dp[i]);
        }
        return res;
    }

    public int LengthOfLIS_NLogN(int[] nums) {
        int len = nums.Length;



        return 0;

    }
}