/*
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to 
a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
using System.Collections.Generic;

public class Solution001 {
    //  O(n^2) runtime, O(1) space
    public int[] TwoSum_Niave(int[] nums, int target) {
        for(int i = 0 ; i < nums.Length-1; i++)
        {
            for (int j = i+1; j<nums.Length; i++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return new int[] { i ,j };
                }
            } 
        }
        return null;           
    }
    // # O(n) runtime, O(n) space
    // Use dictionary and search the difference
    public int[] TwoSum(int[] nums, int target)
    {
        var dict = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            var diff = target - nums[i];
            if(dict.ContainsKey(diff))
            {
                return new int[] { dict[diff], i };
            }
            else
            {
                if(!dict.ContainsKey(nums[i]))
                    dict.Add(nums[i], i);
            }
        }

        return null;
    }
}