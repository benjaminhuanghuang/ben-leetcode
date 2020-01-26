package cn.huang.leetcode;

import java.util.Arrays;

/*
719. Find K-th Smallest Pair Distance

Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is
defined as the absolute difference between A and B.

Example 1:

Input:
nums = [1,3,1]
k = 1
Output: 0
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Note:

    2 <= len(nums) <= 10000.
    0 <= nums[i] < 1000000.
    1 <= k <= len(nums) * (len(nums) - 1) / 2.

 */
public class LC_0719_FindKthSmallestPairDistance {
    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int lf = -1;
        int rt = nums[n - 1] - nums[0];
        while (rt - lf > 1) {
            int mid = lf + (rt - lf) / 2;
            if (count(nums, mid) < k) {
                lf = mid;
            } else {
                rt = mid;
            }
        }
        return rt;
    }

    public int count(int[] nums, int mid) { // <= mid 的个数
        int n = nums.length;
        int cnt = 0;
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j < i && nums[i] - nums[j] > mid) j++;
            cnt += i - j;
        }
        return cnt;
    }
}
