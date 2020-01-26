package cn.huang.leetcode;

import java.util.Arrays;

/*
960. Delete Columns to Make Sorted III
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["babca","bbazb"] and deletion indices {0, 1, 4}, then the final array after deletions is ["bc","az"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has every element (row) in lexicographic order.

For clarity, A[0] is in lexicographic order (ie. A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]), A[1] is in lexicographic order (ie. A[1][0] <= A[1][1] <= ... <= A[1][A[1].length - 1]), and so on.

Return the minimum possible value of D.length.



Example 1:

Input: ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is A = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
Note that A[0] > A[1] - the array A isn't necessarily in lexicographic order.
Example 2:

Input: ["edcba"]
Output: 4
Explanation: If we delete less than 4 columns, the only row won't be lexicographically sorted.
Example 3:

Input: ["ghi","def","abc"]
Output: 0
Explanation: All rows are already lexicographically sorted.


Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
 */

/*
http://www.noteanddata.com/leetcode-960-Delete-Columns-to-Make-Sorted-III-java-solution-note.html


    输入一个字符串数组， 其中的每个字符串的长度都一样
    定义删除一个index的操作是把这个数组里面所有字符串在这个index上的字符都删除，
    定义一个字符串是lexicographic order的，是指这个字符串从前到后都是按字母序的，
    也就是x.charAt(0) <= x.char
    问， 最少删除多少个字符以后，数组里面的每个字符串都是

解题思路分析

    这个题目一开始想的是把所有的可能性都遍历一下， 当然这样复杂度肯定太高， 然后想要么把过程记录下来， 就是用一个递归+memorization的思路， 结果这样还是超时
    这里其实需要从小样本开始分析， 如果只有一个字符串应该怎么处理？
    如果也是逐个删除，同样复杂度会比较高， 但是这里求最少删除多少个，考虑可以用动态规划，
    其实对于一个字符串来说，最少删除多少个可以使字符串变成lexicographic order， 其实就是这个字符串的max Increasing Subsequence.
    , 那么解法就和Leetcode 300 Longest Increasing Subsequence一样

    对于多个字符串，我们也可以用同样的方法，对于每个位置j < i+1，可以检验是否对所有的字符串都有s.charAt(i+1) > s.charat(j),
    如果都成立的话，那么就可以dp[i+1] = Math.max(dp[i+1], dp[j])

 */
public class LC_0960_DeleteColumnstoMakeSorted_III {
    public int minDeletionSize(String[] A) {
        int[] dp = new int[A[0].length()];
        Arrays.fill(dp, 1);
        int max = 1;
        for(int i = 0; i < A[0].length(); ++i) {
            for(int k = 0; k < i; ++k) {
                boolean valid = true;
                for(int j = 0; j < A.length; ++j) {
                    if(A[j].charAt(k) > A[j].charAt(i)) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    dp[i] = Math.max(dp[i], dp[k]+1);
                    max = Math.max(max, dp[i]);
                }
            }
        }
        return A[0].length()-max;
    }
}
