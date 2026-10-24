package cn.huang.leetcode;

import java.util.HashSet;
import java.util.Set;

/*
128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


 */
public class LC_0128_LongestConsecutiveSequence {
    /*
    https://www.programcreek.com/2013/01/leetcode-longest-consecutive-sequence-java/

    Because it requires O(n) complexity, we can not solve the problem by sorting the array first.
    Sorting takes at least O(nlogn) time.

    We can use a HashSet to add and remove elements. HashSet is implemented by using a hash table.
    Elements are not ordered. The add, remove and contains methods have constant time complexity O(1).


     */
    public int longestConsecutive(int[] nums) {
        // if array is empty, return 0
        if (nums.length == 0) {
            return 0;
        }

        Set<Integer> set = new HashSet<Integer>();
        int maxLen = 1;

        for (int n : nums)
            set.add(n);

        for (int n : nums) {
            int left = n - 1;
            int right = n + 1;
            int count = 1;

            while (set.contains(left)) {
                count++;
                set.remove(left);
                left--;
            }

            while (set.contains(right)) {
                count++;
                set.remove(right);
                right++;
            }

            maxLen = Math.max(count, maxLen);
        }

        return maxLen;
    }
}
