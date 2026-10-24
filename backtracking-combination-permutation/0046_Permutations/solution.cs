using System;
using System.Linq;
using System.Collections.Generic;

public class Solution046
{
    public IList<IList<int>> Permute(int[] nums)
    {
        Array.Sort(nums);
        var res = new List<IList<int>>();
        this.PermuteRecursion(res, new List<int>(), nums);
        return res;
    }
    private void PermuteRecursion(List<IList<int>> res, IList<int> combination, int[] nums)
    {
        if (nums.Length == 0)
        {
            res.Add(combination);
            return;
        }

        for (int i = 0; i < nums.Length; i++)
        {
            IList<int> newCombination = new List<int>(combination);
            newCombination.Add(nums[i]);
            this.PermuteRecursion(res, newCombination, nums.Where((e, idx) => idx != i).ToArray());
        }
    }
}