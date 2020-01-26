package cn.huang.leetcode;

/*
768. Max Chunks To Make Sorted II

This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily
distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks"
(partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.

Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.

Note:

    arr will have length in range [1, 2000].
    arr[i] will be an integer in range [0, 10**8].

 */
/*
给你一堆数让你分块，每块独立排序后和整个数组排序的结果相同，问你最多能分为几块。

 */
public class LC_0768_MaxChunksToMakeSorted_II {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int[] right_min = new int[n];            // right_min[i] means the min value to its right
        right_min[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_min[i] = Math.min(arr[i], right_min[i + 1]);
        }
        int ans = 1, left_max = arr[0];
        for (int i = 1; i < n; ++i) {
            if (right_min[i] < left_max) {      // the right side has small value(s), hence cannot split
                left_max = Math.max(left_max, arr[i]);
            } else {
                ++ans;
                left_max = arr[i];
            }
        }
        return ans;

    }
}
