package cn.huang.leetcode;

/*
33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


 */
public class LC_0033_SearchinRotatedSortedArray {
    /*
    // if mid is greater than low, then we know mid is in the left part.
    //  if x >= low and x < mid. search left part, otherwise search right part;
    // if mid is less than low, then we know mid is in the right part.
    //  if x <= high and x > mid. search the right part, otherwise search left part;
    // if mid is equal to low, just increase the low (we do not know where the target x would be)
    // if mid is equal to low, just increase the low (we do not know where the target x would be)

    Time O(logN)
    Space O(1)
     */
    public int search(int[] nums, int target) {
        if (nums == null || nums.length < 1)
            return -1;

        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            if (nums[left] == target)
                return left;
            if (nums[right] == target)
                return right;

            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > nums[left]) // mid located in left part, which is increasing
            {
                if (nums[left] < target && target < nums[mid]) //  target located between left and mid
                    right = mid - 1;
                else   //  target is bigger than mid
                    left = mid + 1;
            } else                       // mid located in right part, which is increasing
            {
                if (nums[mid] < target && target < nums[right])   //target located between mid and right
                    left = mid + 1;
                else   // target is less then mid
                    right = mid - 1;
            }
        }

        return -1;
    }

    // https://www.youtube.com/watch?v=KSZfO65J6hg
    public int search2(int[] nums, int target) {
        if (nums == null || nums.length < 1)
            return -1;

        int left = 0;
        int right = nums.length - 1;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > nums[left]) // mid located in left part, which is increasing
            {
                if (nums[left] < target && target < nums[mid]) //  target located between left and mid
                    right = mid;
                else   //  target is bigger than mid
                    left = mid;
            } else                       // mid located in right part, which is increasing
            {
                if (nums[mid] < target && target < nums[right])   //target located between mid and right
                    left = mid;
                else   // target is less then mid
                    right = mid;
            }
        }
        if (nums[left] == target)
            return left;
        if (nums[right] == target)
            return right;

        return -1;
    }

    // Wrong
    public int search3(int[] nums, int target) {
        if (nums == null || nums.length < 1)
            return -1;

        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > nums[left]) // mid located in left part, which is increasing
            {
                if (nums[left] < target && target < nums[mid]) //  target located between left and mid
                    right = mid;
                else   //  target is bigger than mid
                    left = mid + 1;
            } else                       // mid located in right part, which is increasing
            {
                if (nums[mid] < target && target < nums[right])   //target located between mid and right
                    left = mid + 1;
                else   // target is less then mid
                    right = mid;
            }
        }

        if (nums[right] == target)
            return right;

        return -1;
    }
}
