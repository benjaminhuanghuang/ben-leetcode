package cn.huang.leetcode;

/*
238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the
product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not moves as extra space for the purpose
of space complexity analysis.)

 */
public class LC_0238_ProductofArrayExceptSelf {
    /*
    首先想到的思路是计算全部数字的乘积，然后分别除以num数组中的每一个数（需要排除数字0）。然而，题目要求不能使用除法。
     由于output[i] = (x 0 * x 1 * ... * x[i-1] ) * (x[i+1] * .... * x[n-1] )

    因此执行两趟循环：

    第一趟正向遍历数组，计算x 0 ~ x i-1 的乘积

    第二趟反向遍历数组，计算x i+1 ~ x n-1 的乘积
    */
    public int[] productExceptSelf(int[] nums) {
        if (nums == null || nums.length < 1)
            return nums;
        int n = nums.length;

        int[] res = new int[n];
        int l = 1; // l = prod(nums[0] ~ nums[i - 1])
        int r = 1; // r = prod(nums[i + 1] ~ nums[n - 1])
        for (int i = 0; i < n; ++i) {
            res[i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            res[i] *= l;
            res[n - i - 1] *= r;
            l *= nums[i];
            r *= nums[n - i - 1];
        }

        return res;
    }
}
