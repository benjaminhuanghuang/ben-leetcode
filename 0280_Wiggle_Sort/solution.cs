/*
    280. Wiggle Sort
    # 324

    Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

    For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

using System;

public class Solution280 {
    public void wiggleSort(int[] nums) {
        // 先将数组排序
        Array.Sort(nums);
        // 将数组中一对一对交换
        for(int i = 2; i < nums.Length; i+=2){
            int tmp = nums[i-1];
            nums[i-1] = nums[i];
            nums[i] = tmp;
        }
    }
}