package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
47. Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]


 */


/*
https://www.youtube.com/watch?v=GpfzOIZQt5s
 */
public class LC_0047_Permutations_II {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        helper(res, new ArrayList<>(), nums, used);
        return res;
    }

    private void helper(List<List<Integer>> res, List<Integer> combination, int[] nums, boolean[] used) {
        if (combination.size() == nums.length) {
            res.add(new ArrayList<>(combination));  // note! DO not use res.add(combination);
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1] || used[i]) {
                continue;
            }
            used[i] = true;
            combination.add(nums[i]);
            helper(res, combination, nums, used);
            combination.remove(combination.size() - 1);
            used[i] = false;
        }
    }

    public List<List<Integer>> permuteUnique2(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        helper2(res, nums, 0);
        return res;
    }

    private void helper2(List<List<Integer>> res, int[] nums, int start) {
        if (start == nums.length) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < nums.length; i++) {
                list.add(nums[i]);
            }
            res.add(list);
        }
        for (int i = start; i < nums.length; i++) {
            if (isUsed(nums, start, i))
                continue;
            swap(nums, start, i);
            helper2(res, nums, start + 1);
            swap(nums, start, i);
        }
    }

    private void swap(int[] nums, int m, int n) {
        int temp = nums[m];
        nums[m] = nums[n];
        nums[n] = temp;
    }

    private boolean isUsed(int[] nums, int start, int j) {
        for (int x = start; x < j; x++) {
            if (nums[x] == nums[j])
                return true;
        }
        return false;
    }
}
