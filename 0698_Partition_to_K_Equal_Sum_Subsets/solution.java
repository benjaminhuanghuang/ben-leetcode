package cn.huang.leetcode;

import java.util.Arrays;

/*
698. Partition to K Equal Sum Subsets

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into
k non-empty subsets whose sums are all equal.



Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.



Note:

    1 <= k <= len(nums) <= 16.
    0 < nums[i] < 10000.


 */
public class LC_0698_PartitiontoKEqualSumSubsets {
    /*
    https://www.jiuzhang.com/solution/partition-to-k-equal-sum-subsets/
     */
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }

        if (sum % k != 0) {
            return false;
        }

        int target = sum / k;
        Arrays.sort(nums);
        if (nums[nums.length - 1] > target) {
            return false;
        }

        int row = nums.length - 1;
        while (row >= 0 && nums[row] == target) {
            --row;
            --k;
        }

        return search(new int[k], row, nums, target);
    }

    public boolean search(int[] groups, int row, int[] nums, int target) {
        if (row < 0) {
            return true;
        }

        int v = nums[row--];

        for (int i = 0; i < groups.length; ++i) {
            if (groups[i] + v <= target) {
                groups[i] += v;
                if (search(groups, row, nums, target)) {
                    return true;
                }
                groups[i] -= v;
            }

            if (groups[i] == 0) {   // fill groups[i] ahead of groups[i + 1]
                break;
            }
        }

        return false;
    }
}
