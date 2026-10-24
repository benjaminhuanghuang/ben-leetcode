/*
216. Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 
can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/
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