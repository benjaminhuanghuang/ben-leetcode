package cn.huang.leetcode;

/*
327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:

Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.

 */

/*
给了一个数组，又给了一个下限和一个上限，求有多少个不同的区间使得每个区间的和在给定的上下限之间。
 */
public class LC_0327_CountofRangeSum {
    long[] counts;
    int lower, upper;

    public int countRangeSum(int[] nums, int lower, int upper) {
        int length = nums.length;
        this.lower = lower;
        this.upper = upper;
        if (length <= 0) return 0;
        counts = new long[nums.length];
        counts[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            counts[i] = counts[i - 1] + nums[i];
        }
        return countNum(nums, 0, length - 1);
    }

    private int countNum(int[] nums, int left, int right) {
        if (left == right) {
            if (nums[left] >= lower && nums[right] <= upper) return 1;
            return 0;
        }
        int mid = (left + right) / 2;
        int total = 0;
        for (int i = left; i <= mid; i++) {
            for (int j = mid + 1; j <= right; j++) {
                long tmpNum = counts[j] - counts[i] + nums[i];
                if (tmpNum >= lower && tmpNum <= upper)
                    ++total;
            }
        } //采用二分法
        return total + countNum(nums, left, mid) + countNum(nums, mid + 1, right);
    }
}
