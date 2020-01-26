package cn.huang.leetcode;

import java.util.TreeSet;

/*
220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute
difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false


 */
public class LC_0220_ContainsDuplicate_III {
    /*
    time O(n*k)     space O(1)
     */
    public boolean containsNearbyAlmostDuplicate_Naive(int[] nums, int k, int t) {
        if (nums == null || nums.length == 0)
            return false;


        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j - i <= k && j < nums.length; j++) {
                if (Math.abs((long) (nums[j]) - (long) (nums[i])) <= t)
                    return true;
            }
        }

        return false;
    }

    /*
    https://www.youtube.com/watch?v=pcNkFM-Dkqg
    TreeSet
     */
    public boolean containsNearbyAlmostDuplicate2(int[] nums, int k, int t) {
        if (nums == null || nums.length == 0)
            return false;

        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            Long floor = set.floor((long) nums[i] + t);
            Long ceil = set.ceiling((long) nums[i] - t);  // smallest number larger than

            if (floor != null && floor > nums[i] || ceil != null && ceil <= nums[i])
                return true;

            set.add((long) nums[i]);

            if (i >= k)
                set.remove((long) nums[i - k]);
        }

        return false;
    }
}
