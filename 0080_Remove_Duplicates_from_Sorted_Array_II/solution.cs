/*
80. Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.

Refer to 26. Remove Duplicates from Sorted Array

*/

using System;

public class Solution080 {
    // 当nums[end-1] = nums[end] = nums[i]时，nums[i]为重复元素需跳过。
    // 而实际只需要比较A[end-1]和A[i]，因为当A[end-1] = A[i]时，
    // 根据sorted arry特性必然也有A[end]=A[end-1]。

    public int RemoveDuplicates(int[] nums) {
        if(nums == null)
            return 0;
        if(nums.Length < 3)
            return nums.Length;
        
        int end = 1;
        for(int i=2; i<nums.Length; i++) {
            if(nums[i]!= nums[end-1]) 
                nums[++end] = nums[i];
        }
        return end+1;
    }
}