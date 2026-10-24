using System.Linq;
using System.Collections.Generic;


public class Solution216 {
    public IList<IList<int>> CombinationSum3(int k, int n) {
         var result = new List<IList<int>>();
        var combination = new List<int>();
        var nums = Enumerable.Range(1, 9).ToList();

        CombinationSum3Helper(k, n, nums, combination, result);
        return result;
    }

    public void CombinationSum3Helper(int k, int n, List< int> nums, List<int> combination, List<IList<int>> result)
    {
        if(k < 0)
        {
            return;
        }
        if(k == 0)
        {
            if(n == 0)
            {
                result.Add(new List< int>(combination));
            }

            return;
        }

        for (int i = 0; i < nums.Count; i ++)
        {
            combination.Add(nums[i]);
            var newNums = nums.GetRange(i + 1, nums.Count - i - 1);
            CombinationSum3Helper(k - 1, n - nums[i], newNums, combination, result);
            combination.RemoveAt(combination.Count - 1);
        }
    }
}