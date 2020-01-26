/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution047
{
    public IList<IList<int>> PermuteUnique(int[] nums)
    {
        Array.Sort(nums);
        var res = new List<IList<int>>();
        this.PermuteRecursion(res, new List<int>(), nums);
        return res;
    }

    private void PermuteRecursion(List<IList<int>> res, List<int> combination, int[] nums)
    {
        if (nums.Length == 0)
        {
            res.Add(combination);
            return;
        }
        for (int i = 0; i < nums.Length; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            var newCombination = new List<int>(combination);
            newCombination.Add(nums[i]);
            this.PermuteRecursion(res, newCombination, nums.Where((e, idx) => idx != i).ToArray());
        }
    }
}