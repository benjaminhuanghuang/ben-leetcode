package cn.huang.leetcode;

/*
    53. Maximum Subarray
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the
    largest sum and return its sum.

    Example:

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
    Follow up:

    If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach,
    which is more subtle.
 */
public class LC_0053_MaximumSubarray {
    /*
    从头遍历这个数组。对于数组中的其中一个元素，它只有两个选择：

     1. 要么加入之前的数组加和之中（跟别人一组）

     2. 要么自己单立一个数组（自己单开一组）

     所以对于这个元素应该如何选择，就看他能对哪个组的贡献大。如果跟别人一组，能让总加和变大，还是跟别人一组好了；
     如果自己起个头一组，自己的值比之前加和的值还要大，那么还是自己单开一组好了。

    所以利用一个sum数组，记录每一轮sum的最大值，sum[i]表示当前这个元素是跟之前数组加和一组还是自己单立一组好，

     */
    public int maxSubArray(int[] nums) {
        int[] sum = new int[nums.length];
        int max = nums[0];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = Math.max(nums[i], sum[i - 1] + nums[i]);
            max = Math.max(max, sum[i]);
        }
        return max;
    }
}
