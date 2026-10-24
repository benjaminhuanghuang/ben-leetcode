package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


 */
public class LC_0015_3Sum {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        if (nums == null || nums.length < 3)
            return res;
        int len = nums.length;
        Arrays.sort(nums);
        // 注意，对于 num[i]，寻找另外两个数时，只要从 i+1 开始找就可以了。
        // 这种写法，可以避免结果集中有重复，因为数组时排好序的，
        //所以当一个数被放到结果集中的时候，其后面和它相等的直接被跳过。
        for (int i = 0; i < len; i++) {
            // 可省，目的减少无意义的循环
            if (nums[i] > 0)
                break;
            // 避免重复！！！！
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 往后找，避免重复
            int begin = i + 1;
            int end = len - 1;
            while (begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if (sum == 0) {
                    res.add(Arrays.asList(nums[i], nums[begin], nums[end]));
                    begin++;
                    end--;
                    // 避免重复！！！！
                    while (begin < end && nums[begin] == nums[begin - 1])
                        begin++;
                    while (begin < end && nums[end] == nums[end + 1])
                        end--;
                } else if (sum > 0)
                    end--;
                else
                    begin++;
            }
        }
        return res;
    }
}
