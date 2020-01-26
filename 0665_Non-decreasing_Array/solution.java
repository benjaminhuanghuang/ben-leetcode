package cn.huang.leetcode;

/*
    665. Non-decreasing Array
    Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most
    1 element.

    We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 */
public class LC_0665_NondecreasingArray {
    public boolean checkPossibility(int[] nums) {
        if (nums == null || nums.length <= 1) return true;
        boolean found = false;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                if (found) return false;
                else {
                    if (i - 2 >= 0 && nums[i] < nums[i - 2])
                        nums[i] = nums[i - 1];
                    found = true;
                }
            }
        }
        return true;
    }
}
