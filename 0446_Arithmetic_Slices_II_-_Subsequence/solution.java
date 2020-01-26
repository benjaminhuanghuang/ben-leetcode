package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
446. Arithmetic Slices II - Subsequence   [413]

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any
two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.

1, 1, 2, 5, 7


A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of
integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk]
is arithmetic. In particular, this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is
guaranteed to be less than 231-1.

Example:

Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

 */
public class LC_0446_ArithmeticSlices_II_Subsequence {
    /*
    It's a DP problem. Since for each element A[i] when it's part of a arithmetic sequence, its difference can be
    different. For example, [2, 4, 6] and [2, 6, 10]. For number 2 and 6, they can be in different arithmetic sequences.

    So for each dp[i], we need to maintain a hashmap, the key is the diff, and value is the number of pairs with this diff.

    Then for each pair [i, j] in the array A, we check if we have seen the diff before. If yes, we add a pair and calculate
    the number of subsequences added in.
     */
    public int numberOfArithmeticSlices(int[] A) {
        if (A == null || A.length < 3) {
            return 0;
        }

        Map<Integer, Integer>[] dp = (Map<Integer, Integer>[]) new HashMap<?, ?>[A.length];

        for (int i = 0; i < dp.length; i++) {
            dp[i] = new HashMap<>();
        }

        int ans = 0;

        for (int i = 0; i < A.length; i++) {
            for (int j = i + 1; j < A.length; j++) {
                long diff = (long) A[j] - (long) A[i];
                if (diff > Integer.MAX_VALUE || diff < Integer.MIN_VALUE) {
                    continue;
                }

                int delta = (int) diff;
                int vali = dp[i].getOrDefault(delta, 0);
                ans += vali;

                vali += 1;
                int valj = dp[j].getOrDefault(delta, 0);
                dp[j].put(delta, vali + valj);
            }
        }

        return ans;
    }
}
