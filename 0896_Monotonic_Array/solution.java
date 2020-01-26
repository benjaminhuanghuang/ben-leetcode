package cn.huang.leetcode;
/*
    896	 Monotonic Array

    An array is monotonic if it is either monotone increasing or monotone decreasing.

    An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

    Return true if and only if the given array A is monotonic.

    Example 1:

    Input: [1,2,2,3]
    Output: true

    Example 2:

    Input: [6,5,4,4]
    Output: true
 */

public class LC_0896_MonotonicArray {
    public boolean isMonotonic(int[] A) {
        if(A == null)
            return false;

        boolean inc = true;
        boolean dec = true;

        for (int i = 1; i < A.length; ++i) {
            inc &= A[i] >= A[i - 1];
            dec &= A[i] <= A[i - 1];
        }

        return inc || dec;
    }
}
