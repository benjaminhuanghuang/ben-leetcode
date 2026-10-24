/*
39. Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where 
the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

https://miafish.wordpress.com/2015/04/24/leetcode-ojc-combination-sum-ii/

*/
using System;
using System.Collections;
using System.Collections.Generic;


public class Solution039 {
    
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        Array.Sort(candidates);
        var res = new List<IList<int>>();
        CombinationSumRecursion(candidates, target, new List<int>(), res, 0);
        return res;
    }

    public void CombinationSumRecursion(int[] candidates, int target, IList<int> combination, IList<IList<int>> res, int index)
    {
        if (target == 0)
        {
            res.Add(new List<int>(combination));
        }

        for (int i = index; i < candidates.Length && target >= candidates[i]; i++)
        {
            var choose = candidates[i];
            combination.Add(choose);
            CombinationSumRecursion(candidates, target - choose, combination, res, i);
            combination.RemoveAt(combination.Count - 1);
        }
    }
}