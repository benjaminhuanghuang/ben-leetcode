package cn.huang.leetcode;

/*
152. Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which
has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


 */
public class LC_0152_MaximumProductSubarray {
    /*
        https://miafish.wordpress.com/2015/02/27/leetcode-ojc-maximum-product-subarray/

        use dynamic programming. two values store up to current(must include current value) max value and min value.
        formula is like this.

        A[i] >= 0

        list[i].Max = Math.Max(A[i], list[i – 1].Max * A[i]);
        list[i].Min = Math.Min(A[i], list[i – 1].Min * A[i]);

        A[i] < 0

        list[i].Min = Math.Min(A[i], list[i – 1].Max * A[i]);
        list[i].Max = Math.Max(A[i], list[i – 1].Min * A[i]);
    */
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        if (nums.length == 1)
            return nums[0];
        // 负数 * 负数
        int[] maxhere = new int[nums.length];
        int[] minhere = new int[nums.length];

        // init
        maxhere[0] = nums[0];
        minhere[0] = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.length; i++) {
            maxhere[i] = Math.max(Math.max(maxhere[i - 1] * nums[i], nums[i]), minhere[i - 1] * nums[i]);
            minhere[i] = Math.min(Math.min(minhere[i - 1] * nums[i], nums[i]), maxhere[i - 1] * nums[i]);
            res = Math.max(res, maxhere[i]);
        }
        return res;
    }
}
