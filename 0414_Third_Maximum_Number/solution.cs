/*
414. Third Maximum Number

Given an array of integers, return the 3rd Maximum Number in this array, 
if it doesn't exist, return the Maximum Number. The time complexity must be O(n) or less.
*/
using System;

public class Solution414 {
    public int ThirdMax(int[] nums) {
        long max1 = long.MinValue, max2= long.MinValue, max3=long.MinValue;
        
        for (int i =0; i < nums.Length; i++)
        {
            if (nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (max1 > nums[i] && nums[i] > max2)
            {
                max3 = max2;                  
                max2 = nums[i]; 
            }
            else if (max2 > nums[i] && nums[i] > max3)
            {
                max3 = nums[i];
            }
        }
        if (max3 == long.MinValue)
            return (int)max1;
        return (int)max3;
    }
}