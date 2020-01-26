package cn.huang.leetcode;

import java.util.Arrays;

/*
    26	Remove Duplicates from Sorted Array

    Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */
public class LC_0026_RemoveDuplicatesfromSortedArray {
    // Return the new length
    public int removeDuplicates(int[] nums) {
        if (nums.length < 2)
            return nums.length;

        int end = 0;
        int i = 1;

        while (i < nums.length) {
            if (nums[i] != nums[end]) {
                nums[++end] = nums[i];
            }
            i++;
        }

        return end + 1;
    }

    public int[] removeDuplicates_2(int[] nums) {
        if (nums.length < 2)
            return nums;

        int j = 0;
        int i = 1;

        while (i < nums.length) {
            if (nums[i] == nums[j]) {
                i++;
            } else {
                j++;
                nums[j] = nums[i];
                i++;
            }
        }
        // Copy array
        int[] B = Arrays.copyOf(nums, j + 1);

        return B;
    }
}
