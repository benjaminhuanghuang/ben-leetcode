package cn.huang.leetcode;

/*
 704. Binary Search

 */
public class LC_0704_BinarySearch {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return -1;

        int left = 0;
        int right = nums.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                return mid;
            }
        }
        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }
        return -1;
    }

    public int search_better(int[] nums, int target) {
        if (nums == null || nums.length == 0)
            return -1;

        int low = 0;
        int high = nums.length - 1;
        int mid = (high + low) / 2;
        while (low <= high) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
            mid = (low + high) / 2;
        }
        return -1;
    }
}
