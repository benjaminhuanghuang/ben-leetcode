package cn.huang.leetcode;

/*
35. Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where
it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
 */
public class LC_0035_SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        // l + 1 < r
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid;
            } else {
                return mid;
            }
        }
        if (target <= nums[l])
            return l;
        else if (target <= nums[r])
            return r;
        else
            return r + 1;
    }

    /*
    https://www.youtube.com/watch?v=suG-CGyV8Ss
     */
    public int searchInsert_better(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return l;
    }
}
