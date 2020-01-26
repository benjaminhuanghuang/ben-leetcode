package cn.huang.leetcode;

import java.util.Arrays;

/*
376. Wiggle Subsequence

A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate
between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence
with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and
negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences
are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence
is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the
remaining elements in their original order.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.

Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2

Follow up:
Can you do it in O(n) time?

 */
public class LC_0376_WiggleSubsequence {
    /*
    维护两个dp数组p和q，其中p[i]表示到i位置时首差值为正的摆动子序列的最大长度，q[i]表示到i位置时首差值为负的摆动子序列的最大长度。
    从i=1开始遍历数组，然后对于每个遍历到的数字，再从开头位置遍历到这个数字，然后比较nums[i]和nums[j]，分别更新对应的位置，参见代码如下：
     */
    public int wiggleMaxLength(int[] nums) {
        if (nums.length == 0)
            return 0;
        int[] p = new int[nums.length];
        int[] q = new int[nums.length];

        Arrays.fill(p, 1);
        Arrays.fill(q, 1);


        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) p[i] = Math.max(p[i], q[j] + 1);
                else if (nums[i] < nums[j]) q[i] = Math.max(q[i], p[j] + 1);
            }
        }
        return Math.max(p[nums.length - 1], q[nums.length - 1]);
    }

    public int wiggleMaxLength2(int[] nums) {
        int p = 1, q = 1, n = nums.length;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                p = q + 1;
            else if (nums[i] < nums[i - 1])
                q = p + 1;
        }
        return Math.min(n, Math.max(p, q));
    }
}
