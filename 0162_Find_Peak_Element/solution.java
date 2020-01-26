package cn.huang.leetcode;

/*
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Your solution should be in logarithmic complexity.
 */
public class LC_0162_FindPeakElement {
    public int findPeakElement(int[] nums) {
        int low = 0, high = nums.length - 1;
        // 等号
        while (low <= high) {
            // 无符号右移，忽略符号位，空位都以0补齐
            int mid = (low + high) >>> 1;
            // 如果[mid-1]>[mid]，那么peak肯定在[low]和[mid-1]之间（闭区间）
            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
                high = mid - 1;
                // 如果mid+1大，那么peak肯定在mid+1和hi之间（闭区间）
            else if (mid + 1 < nums.length && nums[mid] < nums[mid + 1])
                low = mid + 1;
                // 其他情况（peak在开头或者结尾，或者中间）
            else
                return mid;
        }
        return -1;
    }
}
