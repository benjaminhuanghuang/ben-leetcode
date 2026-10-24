using System;
using System.Collections.Generic;


public class Solution040 {
    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);
        var res = new List<IList<int>>();
        CombinationSumHelper(candidates, target, 0, new List<int>(), res);
        return res; 
    }


    private void CombinationSumHelper(int[] candidates, int target, int index, IList<int> combination, IList<IList<int>> res)
    {
        if (target == 0)
        {
            res.Add(new List<int>(combination));
            return;
        }
        // Important!
        if (target < 0)
        {
            return;
        }
        for (int j = index; j < candidates.Length; j++)         
        {             
            // candidates is sorted
            // 因为给定数组元素出现重复，如果当前递归符合要求，紧接的递归会再次出现同样的结果
            Console.WriteLine(string.Join(",", combination));
            if (j > index && candidates[j] == candidates[j - 1]) 
            {
                //Console.WriteLine(string.Join(",", combination));
            
                continue;
            }
            combination.Add(candidates[j]);
            CombinationSumHelper(candidates, target - candidates[j] , j + 1, combination, res);
            combination.RemoveAt(combination.Count - 1);
        }
    }   
}