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