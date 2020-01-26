package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
491. Increasing Subsequences  [Yahoo]

 Given an integer array, your task is to find all the different possible increasing subsequences of the given array,
 and the length of an increasing subsequence should be at least 2 .

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

Note:

    The length of the given array will not exceed 15.
    The range of integer in the given array is [-100,100].
    The given array may contain duplicates, and two equal integers should also be considered as a special case of
    increasing sequence.

 */
public class LC_0491_IncreasingSubsequences {
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length == 0)
            return res;

        dfs(nums, 0, new ArrayList<Integer>(), res);
        return res;
    }

    private void dfs(int[] nums, int start, List<Integer> temp, List<List<Integer>> res) {
        if (temp.size() > 1) {
            res.add(new ArrayList<>(temp));
        }

        Set<Integer> used = new HashSet<>();   //防止重复

        for (int i = start; i < nums.length; i++) {
            if (used.contains(nums[i])) continue;
            if (temp.size() == 0 || nums[i] >= temp.get(temp.size()-1)) {
                temp.add(nums[i]);
                used.add(nums[i]);
                dfs(nums, i+1, temp, res); //next dfs doesn't have used, yeah
                temp.remove(temp.size()-1);
            }
        }
    }
}
