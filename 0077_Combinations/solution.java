package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*

77. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


 */
public class LC_0077_Combinations {
    /*
    https://www.youtube.com/watch?v=-Nzrl6hCRKc

    time O(n^ min{k, n-k}) , space O(n)

     */
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        helper(res, new ArrayList<>(), n, k, 1);
        return res;
    }

    private void helper(List<List<Integer>> res, List<Integer> combination, int n, int k, int start) {
        if (k == 0) {
            res.add(new ArrayList<>(combination));
            return;
        }

        for (int i = start; i <= n; i++) {
            combination.add(i);
            helper(res, combination, n, k - 1, i + 1);
            combination.remove(combination.size() - 1);
        }
    }
}
