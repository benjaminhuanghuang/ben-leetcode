package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]



 */
public class LC_0090_Subsets_II {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        helper(nums, res, 0, new ArrayList<>());
        return res;
    }
    private void helper(int[] nums, List<List<Integer>> res, int start, List<Integer> combination) {
        res.add(new ArrayList<>(combination));

        for (int i = start; i < nums.length; i++) {
            if (i != start && nums[i] == nums[i-1])    //
            {
                continue;
            }
            combination.add(nums[i]);
            helper(nums, res, i + 1, combination);// Note! i+1 , not pos +1
            combination.remove(combination.size() - 1);
        }
    }
}
