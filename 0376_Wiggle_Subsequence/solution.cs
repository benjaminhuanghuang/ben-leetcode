/*
376. Wiggle Subsequence

A sequence of numbers is called a "wiggle sequence" if the differences between successive numbers strictly 
alternate between positive and negative. The first difference (if one exists) may be either positive or 
negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately 
positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first 
because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. 
A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original 
sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?

*/
using System;

public class Solution376 {
    //https://www.hrwhisper.me/leetcode-wiggle-subsequence/
    //4 5 6  3 2 1这几个数中，4为起点，那么5和6中，我们肯定选6啊~因为之后的数要求小于5，小于5的必定也小于6 比如改为4 5 6 5，
    //之前要是选5就没办法继续往下了。。
    public int WiggleMaxLength(int[] nums) {
        if (nums.Length == 0) 
            return 0;
		int n = nums.Length;
		int ans = 1;
		for (int i = 1, j = 0; i < n; j = i,i++) 
        {
			if (nums[j] < nums[i]) 
            {
				ans++;
				while (i + 1 < n && nums[i] <= nums[i + 1]) 
                    i++;
			}
			else if (nums[j] > nums[i]) 
            {
				ans++;
				while (i + 1 < n && nums[i] >= nums[i + 1]) 
                    i++;
			}
		}
		return ans;
    }
    //http://www.cnblogs.com/grandyang/p/5697621.html
    // 如果当前数字比前一个数字大，则p=q+1，如果比前一个数字小，则q=p+1，
    // 最后取p和q中的较大值跟n比较，取较小的那个：
    public int WiggleMaxLength_2(int[] nums) {
        if (nums.Length == 0) 
            return 0;
		int n = nums.Length;
        int p =1, q = 1;
		for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) 
                p = q + 1;
            else if (nums[i] < nums[i - 1]) 
                q = p + 1;
        }
        return Math.Min(n, Math.Max(p, q));
    }
}

