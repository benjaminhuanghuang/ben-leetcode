package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence:
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

 */
public class LC_0373_FindKPairswithSmallestSums {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        ArrayList<int[]> result = new ArrayList<int[]>();

        if (nums1 == null || nums2 == null || nums1.length == 0 || nums2.length == 0) {
            return result;
        }

        // Important!
        // k's max value is all possible pair, if arrays are too short
        k = Math.min(k, nums1.length * nums2.length);

        // array to track index in nums2
        int[] idx = new int[nums1.length];

        while (result.size() < k) {
            int min = Integer.MAX_VALUE;
            int j = -1;
            for (int i = 0; i < nums1.length; i++) {
                if (idx[i] < nums2.length && nums1[i] + nums2[idx[i]] < min) {
                    min = nums1[i] + nums2[idx[i]];
                    j = i;
                }
            }

            result.add(new int[]{nums1[j], nums2[idx[j]]});
            idx[j]++;
        }

        return result;
    }
}
