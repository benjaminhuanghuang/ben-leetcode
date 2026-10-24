package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations
in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.   [!]

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]


 */
public class LC_0040_CombinationSum_II {
    /*
    https://www.youtube.com/watch?v=5ybHmOt3-34

    [10,1,2,7,6,1,5] sort and get [1,1,2,5,6,7,10]

     */
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        List<List<Integer>> res = new ArrayList<>();
        if (candidates == null || candidates.length == 0)
            return res;
        Arrays.sort(candidates);    // for removing duplicated

        helper(res, new ArrayList<>(), candidates, target, 0);
        return res;
    }

    private void helper(List<List<Integer>> res, List<Integer> combination, int[] candidates, int target, int start) {
        if (target < 0)
            return;
        if (target == 0) {
            res.add(new ArrayList<>(combination));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (i != start && candidates[i] == candidates[i - 1])
                continue;
            combination.add(candidates[i]);
            helper(res, combination, candidates, target - candidates[i], i + 1);   // i + 1 it is the difference with LC #39
            combination.remove(combination.size() - 1);
        }
    }
}
