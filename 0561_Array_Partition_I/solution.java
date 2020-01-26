package cn.huang.leetcode;

import java.util.Arrays;

/*
    561. Array Partition I
    Given an array of 2n integers, your task is to group these integers into n pairs of integer,
    say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

    Example 1:
    Input: [1,4,3,2]

    Output: 4
    Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 */
public class LC_0561_ArrayPartition_I {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length; i += 2) {
            sum += nums[i];
        }
        return sum;
    }

    //https://www.youtube.com/watch?v=wDU72F6dhS4
    public int arrayPairSum_Better(int[] nums) {
        return 0;
    }
}
