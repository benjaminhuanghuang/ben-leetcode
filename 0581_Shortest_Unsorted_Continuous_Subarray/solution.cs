/*
581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray 
in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in 
ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
 */

using System;
 public class Solution581 {
    public int FindUnsortedSubarray(int[] nums) {
        if(nums == null || nums.Length <=1)
            return 0;
        
        int[] sorted = new int[nums.Length];
        Array.Copy(nums, sorted, nums.Length);
        Array.Sort(sorted);
        int len = 0;
        for (int i = 0; i < nums.Length; i++){
            if (nums[i] == sorted[i]) len++;
            else break;
        }
        for (int j = nums.Length-1; j >=0; j--){
            if (nums[j] == sorted[j]) len++;
            else break;
        }
        return Math.Max(0, nums.Length-len);
    }
}