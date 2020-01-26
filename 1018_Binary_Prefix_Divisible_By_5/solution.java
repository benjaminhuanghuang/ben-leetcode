package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
    1018. Binary Prefix Divisible By 5

    Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number
    (from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Example 1:

Input: [0,1,1]
Output: [true,false,false]
Explanation:
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible
by 5, so answer[0] is true.

Example 2:

Input: [1,1,1]
Output: [false,false,false]

Example 3:

Input: [0,1,1,1,1,1]
Output: [true,false,false,false,true,false]

 */

/*
给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。

 */
public class LC_1018_BinaryPrefixDivisibleBy5 {
    public List<Boolean> prefixesDivBy5_overflow(int[] A) {
        List<Boolean> res = new ArrayList<>();
        int curr = 0;
        for (int i = 0; i < A.length; i++) {
            curr <<= 1;
            curr += A[i];
            res.add(curr % 5 == 0);
        }
        return res;
    }

    public List<Boolean> prefixesDivBy5(int[] A) {
        for (int i = 1; i < A.length; i++) {
            A[i] += A[i - 1] * 2 % 5;
        }
        List<Boolean> res = new ArrayList<>();
        for (int i = 0; i < A.length; i++) {
            res.add(A[i] % 5 == 0);
        }
        return res;
    }
}
