/*
152. Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/

using System;

public class Solution152 {
    // https://miafish.wordpress.com/2015/02/27/leetcode-ojc-maximum-product-subarray/
    public int MaxProduct(int[] nums) {
        var max_end_here = new int[nums.Length];
        var min_end_here = new int[nums.Length];

        max_end_here[0] = nums[0];
        min_end_here[0] = nums[0];

        var max = max_end_here[0];

        for (int i = 1; i < nums.Length; i++)
        {
            max_end_here[i] = Math.Max(nums[i], Math.Max(max_end_here[i - 1]*nums[i], min_end_here[i - 1]*nums[i]));
            max = Math.Max(max, max_end_here[i]);
            min_end_here[i] = Math.Min(nums[i], Math.Min(min_end_here[i - 1]*nums[i], max_end_here[i - 1]*nums[i]));
        }

        return max;
    }
}