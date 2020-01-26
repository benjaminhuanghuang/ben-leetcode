package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
78. Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
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
public class LC_0078_Subsets {
    /*
    Time: O(2^n)
    Space O(n)
     */
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        helper(nums, res, 0, new ArrayList<>());
        return res;
    }

    private void helper(int[] nums, List<List<Integer>> res, int start, List<Integer> combination) {
        res.add(new ArrayList<>(combination));

        for (int i = start; i < nums.length; i++) {
            combination.add(nums[i]);
            helper(nums, res, i + 1, combination);
            combination.remove(combination.size() - 1);
        }
    }
}
