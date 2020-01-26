package cn.huang.leetcode;

import java.util.Arrays;

/*
945. Minimum Increment to Make Array Unique

Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to make every value in A unique.



Example 1:

Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].
Example 2:

Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 */
public class LC_0945_MinimumIncrementtoMakeArrayUnique {
    public int minIncrementForUnique(int[] A) {
        if (A.length == 0)
            return 0;

        Arrays.sort(A);
        int res = 0;
        int prev = A[0];
        //prev 表示当前不重复的数字已经增加到哪里了，所以，当下一个数字到来的时候，它应该增加到这个数字的位置，可以直接求出它需要扩大的步数。
        for (int i = 0; i < A.length; i++) {
            if (A[i] <= prev) {
                prev += 1;
                res += prev - A[i];   // not res += 1
            } else
                prev = A[i];
        }

        return res;
    }
}
