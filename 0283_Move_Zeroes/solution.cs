/*
283. Move Zeroes   #26
 
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative 
order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

public class Solution283 {
    public void MoveZeroes(int[] nums) {
        int pivot = 0;
        for( int i =0 ; i < nums.Length; i++)
        {
            if(nums[i] != 0)
            {
                nums[pivot] = nums[i];
                pivot ++;
            }
        }

        for (int i = pivot; i< nums.Length; i++)
        {
            nums[i] = 0;
        }
    }
}
