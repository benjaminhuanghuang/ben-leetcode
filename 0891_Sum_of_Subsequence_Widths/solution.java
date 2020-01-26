package cn.huang.leetcode;

import java.util.Arrays;

/*
891. Sum of Subsequence Widths

Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A.

As the answer may be very large, return the answer modulo 10^9 + 7.



Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.



Note:

    1 <= A.length <= 20000
    1 <= A[i] <= 20000


 */
public class LC_0891_SumofSubsequenceWidths {
    public int sumSubseqWidths(int[] A) {
        Arrays.sort(A);
        int l = 0, r = A.length - 1;
        int lsum = 0, rsum = 0;
        long d = 1, mod = 1000000007;
        long ans = 0;
        while (l < A.length) {
            lsum += A[l++];
            rsum += A[r--];
            ans += (rsum - lsum) * d;
            ans %= mod;
            d = d * 2 % mod;
        }
        return (int)ans;
    }
}
