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