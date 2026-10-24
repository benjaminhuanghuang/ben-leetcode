/*
15. 3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Reference:  
    2sum
    http://www.jiuzhang.com/solutions/3sum/
*/
using System;
using System.Collections.Generic;


public class Solution015 {
    // https://miafish.wordpress.com/2015/01/21/leetcode-oj-c-3sum/
    public IList<IList<int>> ThreeSum(int[] nums) {
        var res = new List<IList <int>>();
        Array.Sort(nums);

        for (int i = 0; i < nums.Length; i++)
        {
            if(i != 0 && nums[i - 1] == nums[i])   // skip the numbers equals
            {
                continue;
            }
            for (int start = i + 1, end = nums.Length - 1; start < end;)
            {
                if(start != i + 1 && nums[start] == nums[start - 1])
                {
                    start++;
                    continue;
                }

                if(nums[i] + nums[start] + nums[end] == 0)
                {
                    res.Add(new List <int>() { nums[i], nums[start], nums[end] });
                    start++;
                }
                else if(nums[i] + nums[start] + nums[end] < 0)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }

        return res;
    }
}

