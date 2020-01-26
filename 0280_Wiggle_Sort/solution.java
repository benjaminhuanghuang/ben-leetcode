package cn.huang.leetcode;

import java.util.Arrays;

/*
280. Wiggle Sort
 Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

  For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 */
public class LC_0280_WiggleSort {
    //Time Complexity - O(n)， Space Complexity - O(1)
    public void wiggleSort(int[] nums) {
        for(int i = 1; i < nums.length; i++) {
            if(i % 2 == 1) {
                if(nums[i] < nums[i - 1]) {
                    swap(nums, i);
                }
            } else {
                if(i != 0 && nums[i] > nums[i - 1]) {
                    swap(nums, i);
                }
            }
        }
    }

    private void swap(int[] nums, int i) {
        int tmp = nums[i - 1];
        nums[i - 1] = nums[i];
        nums[i] = tmp;
    }

    public void wiggleSort2(int[] nums) {
        // 先将数组排序
        Arrays.sort(nums);
        // 将数组中一对一对交换
        for(int i = 2; i < nums.length; i+=2){
            int tmp = nums[i-1];
            nums[i-1] = nums[i];
            nums[i] = tmp;
        }
    }
}
