package cn.huang.leetcode;

import java.util.Arrays;

/*
164. Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

Note:

    You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    Try to solve it in linear time/space.


 */
public class LC_0164_MaximumGap {
    int maximumGap_Sample(int[] nums) {
        if (nums.length < 2)
            return 0;
        Arrays.sort(nums); //O(nlogn)
        int gap = -1;
        for (int i = 1; i < nums.length; i++) {
            gap = Math.max(gap, nums[i] - nums[i - 1]);
        }
        return gap;
    }

    /*
        https://yuanhsh.iteye.com/blog/2187685
        https://www.youtube.com/watch?v=gsNsgAY-WhE
    */
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) return 0;
        // get the max and min value of the array
        int min = nums[0];
        int max = nums[0];
        for (int val:nums) {
            min = Math.min(min, val);
            max = Math.max(max, val);
        }
        // the minimum possibale gap, ceiling of the integer division
        int gap = (int)Math.ceil((double)(max - min)/(nums.length - 1));
        int[] bucketsMIN = new int[nums.length - 1]; // store the min value in that bucket
        int[] bucketsMAX = new int[nums.length - 1]; // store the max value in that bucket
        Arrays.fill(bucketsMIN, Integer.MAX_VALUE);
        Arrays.fill(bucketsMAX, Integer.MIN_VALUE);
        // put numbers into buckets
        for (int val:nums) {
            if (val == min || val == max) continue;
            int idx = (val - min) / gap; // index of the right position in the buckets
            bucketsMIN[idx] = Math.min(val, bucketsMIN[idx]);
            bucketsMAX[idx] = Math.max(val, bucketsMAX[idx]);
        }
        // scan the buckets for the max gap
        int maxGap = Integer.MIN_VALUE;
        int previous = min;
        for (int i = 0; i < nums.length - 1; i++) {
            if (bucketsMIN[i] == Integer.MAX_VALUE && bucketsMAX[i] == Integer.MIN_VALUE)
                // empty bucket
                continue;
            // min value minus the previous value is the current gap
            maxGap = Math.max(maxGap, bucketsMIN[i] - previous);
            // update previous bucket value
            previous = bucketsMAX[i];
        }
        maxGap = Math.max(maxGap, max - previous); // updata the final max value gap
        return maxGap;
    }
}
