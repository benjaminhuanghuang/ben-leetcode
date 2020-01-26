package cn.huang.leetcode;

/*

786. K-th Smallest Prime Fraction

A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]

Note:

    A will have length between 2 and 2000.
    Each A[i] will be between 1 and 30000.
    K will be between 1 and A.length * (A.length - 1) / 2.

 */

/*
Hua hua
 */
public class LC_0786_KthSmallestPrimeFraction {
    public int[] kthSmallestPrimeFraction(int[] A, int K) {
        double left = 0, right = 1;
        int p = 0, q = 1, cnt = 0, n = A.length;
        while (true) {
            double mid = left + (right - left) / 2.0;
            cnt = 0;
            p = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && A[i] > mid * A[j]) ++j;
                cnt += n - j;
                if (j < n && p * A[j] < q * A[i]) {
                    p = A[i];
                    q = A[j];
                }
            }
            if (cnt == K) return new int[]{p, q};
            else if (cnt < K) left = mid;
            else right = mid;
        }
    }
}