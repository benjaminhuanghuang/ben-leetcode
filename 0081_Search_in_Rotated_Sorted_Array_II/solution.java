package cn.huang.leetcode;

/*
81. Search in Rotated Sorted Array II
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up:

    This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
    Would this affect the run-time complexity? How and why?


 */
/*

相比 #33，有重复数字

 */
public class LC_0081_SearchinRotatedSortedArray_II {
    public boolean search(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return false;

        int start = 0, end = nums.length - 1;
        int mid;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[mid] > nums[start])  // left side
            {
                if (nums[mid] >= target && nums[start] <= target)
                    end = mid;
                else
                    start = mid;
            } else if (nums[mid] < nums[start]) {
                if (nums[mid] <= target && nums[end] >= target)
                    start = mid;
                else
                    end = mid;
            } else  {
                // Important: Handle the worst case 111111110111;
                // nums[mid] == nums[start]
                start++;
            }
        }
        return (nums[start] == target || nums[end] == target);
    }
}
