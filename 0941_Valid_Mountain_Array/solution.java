package cn.huang.leetcode;

/*
941. Valid Mountain Array
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[B.length - 1]
 */
public class LC_0941_ValidMountainArray {
    public boolean validMountainArray(int[] A) {
        boolean up = false;
        boolean down = false;
        for (int i = 1; i < A.length; i++) {
            if (A[i] > A[i - 1]) {
                up = true;
                continue;
            } else if (A[i] < A[i - 1]) {
                down = true;
                while (i < A.length - 1) {
                    if (A[i] <= A[i + 1])
                        return false;
                    i++;
                }
            } else
                return false;
        }
        return up && down;
    }
}
