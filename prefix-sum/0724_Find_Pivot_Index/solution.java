package cn.huang.leetcode;

import java.util.stream.IntStream;

/*
724. Find Pivot Index

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to
the sum of the numbers to the right of the index.

 */
public class LC_0724_FindPivotIndex {
    // Failed when nums are negative number
    public int pivotIndex_error(int[] nums) {
        //special case
        if (nums == null || nums.length <= 2) return -1;

        int left = 0;
        int right = nums.length - 1;
        int leftSum = nums[left], rightSum = nums[right];
        while (left < right - 1) {
            if (leftSum < rightSum) {
                leftSum += nums[++left];
                continue;
            }
            if (rightSum < leftSum) {
                rightSum += nums[--right];
                continue;
            }
            // leftSum == rightSum
            if (left + 2 == right)
                return left + 1;
            else {
                left++;
                right--;
            }
        }
        return -1;
    }

    public int pivotIndex(int[] nums) {
        //special case
        if (nums == null || nums.length <= 2) return -1;
        int sum = IntStream.of(nums).sum();
        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < nums.length; ++i) {
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
}
