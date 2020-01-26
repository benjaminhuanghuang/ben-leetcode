/*
78. Subsets

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

using System; 
using System.Collections.Generic;

public class Solution078 {
    public IList<IList<int>> Subsets(int[] nums) {
        List<IList<int>> res = new List<IList<int>>();
        SubsetsHelper(nums, 0, new List<int>(), res);
        return res;      
    }
    
    private void SubsetsHelper(int[] nums, int index, List<int> combination, List<IList<int>> res)
    {
        if (index <= nums.Length)
        {
            res.Add(new List<int>(combination));
        }
        for (int i = index; i < nums.Length; i++)
        {
            combination.Add(nums[i]);
            SubsetsHelper(nums, i + 1, combination, res);
            combination.RemoveAt(combination.Count - 1);
        }
    }
    
    public IList<IList<int>> Subsets_2(int[] nums) {
        Array.Sort(nums);
        var res = new List<IList< int>>();
        SubsetsRecursion(nums, 0, new List<int>(), res);
        return res;       
    }

    private void SubsetsRecursion(int[] nums, int index, List<int> combination, List<IList< int>> res)
    {
        if (index >= nums.Length)
        {
            res.Add(new List<int>(combination));
            return;
        }

        // add item nums[index] 
        combination.Add(nums[index]);
        this.SubsetsRecursion(nums, index + 1, combination, res);
        combination.RemoveAt(combination.Count - 1);

        // do not add nums[index]
        this.SubsetsRecursion(nums, index + 1, combination, res);
    }
}