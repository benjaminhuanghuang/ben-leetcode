package cn.huang.leetcode;

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]

 */
public class LC_0189_RotateArray {
    public void rotate(int[] nums, int k) {
        int step = k % nums.length;
        rotate(nums, 0, nums.length - 1);
        rotate(nums, 0, step - 1);
        rotate(nums, step, nums.length - 1);

    }


    private void rotate(int[] nums, int start, int end) {
        int left = start;
        int right = end;
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}
