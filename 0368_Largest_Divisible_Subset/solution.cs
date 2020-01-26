/*
368. Largest Divisible Subset

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) 
of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:
    nums: [1,2,3]

    Result: [1,2] (of course, [1,3] will also be ok)

Example 2:
    nums: [1,2,4,8]

    Result: [1,2,4,8]
*/
using System;
using System.Collections.Generic;

public class Solution368 {
    //http://www.cnblogs.com/grandyang/p/5625209.html
    // https://segmentfault.com/a/1190000005922634
    // 较小数对较大数取余一定为0，那么问题就变成了看较大数能不能整除这个较小数。
    // 定义一个动态数组dp，其中dp[i]表示到数字nums[i]位置最大可整除的子集合的长度，
    // 维数组parent，来保存上一个能整除的数字的位置
    // mx和mx_idx分别表示最大子集合的长度和起始数字的位置
    public IList<int> LargestDivisibleSubset(int[] nums) {
        List<int> res = new List<int>();
        Array.Sort(nums);
        int n = nums.Length;
        
        int[] dp = new int[n];
        int[] parent = new int[n];

        int mx = 0, mx_idx = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) 
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (mx < dp[i]) 
                    {
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        for (int i = 0; i < mx; ++i) {
            res.Add(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return res;
    }
}