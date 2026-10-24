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