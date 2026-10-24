/*
90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/
using System;
using System.Collections.Generic;

public class Solution090 {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        Array.Sort(nums);
        var res = new List<IList<int>>();
        this.Subset_Recursion(nums, 0, new List<int>(), res);
        return res; 
    }

    private void Subset_Recursion(int[] nums, int pos, IList<int> combination, IList<IList<int>> res)
    {
        res.Add(new List<int>(combination));
        for (int i = pos; i < nums.Length; i++)
        {
            if (i != pos && nums[i] == nums[i-1])
            {
                continue;
            }
            combination.Add(nums[i]);
            // Note! i+1 , not pos +1
            this.Subset_Recursion(nums, i + 1, combination, res);
            combination.RemoveAt(combination.Count -1);
        }
    }
}
