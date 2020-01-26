/*
491. Increasing Subsequences

Given an integer array, your task is to find all the different possible increasing subsequences 
of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a 
special case of increasing sequence.

 */
using System;
using System.Collections.Generic;
using System.Linq;

public class Solution491
{
    //http://blog.csdn.net/qq_31129455/article/details/54691351
    public IList<IList<int>> FindSubsequences(int[] nums)
    {
        List<List<int>> res = new List<List<int>>();
        helper(res, new List<int>(), nums, 0);
        return new List<IList<int>>(res);
    }

    private void helper(List<List<int>> res, List<int> subList, int[] nums, int start)
    {
        if (subList.Count >= 2)
        {
            res.Add(new List<int>(subList));
        }
        HashSet<int> used = new HashSet<int>();
        for (int i = start; i < nums.Length; i++)
        {
            if(used.Contains(nums[i])) continue;
            if (subList.Count == 0 || subList[subList.Count - 1] <= nums[i])
            {
                used.Add(nums[i]);
                subList.Add(nums[i]);
                helper(res, subList, nums, i + 1);
                subList.RemoveAt(subList.Count - 1);
            }
        }
    }
}