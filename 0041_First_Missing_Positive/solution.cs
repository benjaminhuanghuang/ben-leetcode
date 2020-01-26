/*
41. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

public class Solution041 {
    public int FirstMissingPositive(int[] nums) {
        for (int i = 0; i < nums.Length;)
        {   
            // put i to nums[i-1], so the array looks like: 1, 2, 3, ...
            var value = nums[i]; 
            if (value > 0 && value < nums.Length && value != nums[value-1])
            {
                // swap nums[i] with nums[]
                nums[i] = nums[value-1];
                nums[value-1] = value;
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] != i+1)
            {
                return i+1;
            }
        }

        return nums.Length+1;
    }
}