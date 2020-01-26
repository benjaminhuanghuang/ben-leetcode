package cn.huang.leetcode;

import java.util.Arrays;
import java.util.HashMap;

/*
    217. Contains Duplicate
 */
public class LC_0217_ContainsDuplicate {
    public boolean containsDuplicate_Sore(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }

    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> numsMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (numsMap.containsKey(nums[i])) {
                return true;
            } else {
                numsMap.put(nums[i], 1);
            }
        }
        return false;
    }
}