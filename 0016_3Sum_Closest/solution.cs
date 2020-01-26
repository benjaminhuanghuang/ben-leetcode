/*
16. 3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
using System;

public class Solution016 {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        int res = nums[0]+ nums[1]+ nums[2];
        for (int i = 0; i < nums.Length; i++)
        {
            for (int start = i + 1, end = nums.Length - 1; start < end;)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(Math.Abs(sum - target)< Math.Abs(res - target))
                {
                    res = sum;
                    if (res == target)
                        return res;
                }
                
                if(sum <= target)
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