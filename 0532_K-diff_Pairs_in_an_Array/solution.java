package cn.huang.leetcode;

import java.util.Arrays;
import java.util.HashSet;

/*
    532	 K-diff Pairs in an Array
    Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array.
    Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and
    their absolute difference is k.

 */
public class LC_0532_KdiffPairsinanArray {
    /*
        Find nums[i] + k in the map
        https://www.youtube.com/watch?v=YZmDNEhJscE
     */
    public int findPairs(int[] nums, int k) {
        // k小于0无意义
        if (nums == null || nums.length == 0 || k < 0)
            return 0;

        HashSet<Integer> seen = new HashSet<>();
        HashSet<Integer> used = new HashSet<>();

        int pairs = 0;
        for (int i = 0; i < nums.length; i++) {
            // check nums[i] - k, only return the number of unique pairs.
            if (seen.contains(nums[i] - k) && !used.contains(nums[i] + nums[i] - k)) {
                used.add(nums[i] + nums[i] - k);
                pairs++;
            }
            // check nums[i] + k
            if (seen.contains(nums[i] + k) && !used.contains(nums[i] + nums[i] + k)) {
                used.add(nums[i] + nums[i] + k);
                pairs++;
            }
            seen.add(nums[i]);
        }
        return pairs;
    }

    /*
        two points
        https://www.youtube.com/watch?v=X9Sjsezp9ic
     */
    public int findPairs_muchfaster(int[] nums, int k) {
        // k小于0无意义
        if (nums == null || nums.length == 0 || k < 0)
            return 0;

        Arrays.sort(nums);

        int start = 0, end = 1, pairs = 0;
        while (end < nums.length) {
            if (start == end || nums[start] + k > nums[end]) {
                end++;
            } else if (nums[start] + k < nums[end]) {
                start++;
            } else {
                // find pair
                pairs++;
                start++;
                // start
                //  |
                // [1, 1, ...., 8, 8]
                //              |
                //             end
                while (start < nums.length && nums[start] == nums[start - 1]) {
                    // skip the duplicate
                    start++;
                }
                end = Math.max(end , start + 1);
            }
        }
        return pairs;
    }
}
