package cn.huang.leetcode;
/*
918. Maximum Sum Circular Subarray

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)



Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3

Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3

Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1



Note:

    -30000 <= A[i] <= 30000
    1 <= A.length <= 30000


 */
public class LC_0918_MaximumSumCircularSubarray {
    public int maxSubarraySumCircular(int[] A) {
        int n = A.length;
        int ans = A[0];
        int sum = A[0];
        // 1 interval
        for (int i = 1; i < n; i++) {
            sum = Math.max(sum + A[i], A[i]);
            ans = Math.max(ans, sum);
        }

        int[] rightSum = new int[n];
        int[] rightMax = new int[n];
        rightSum[n - 1] = A[n - 1];
        rightMax[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + A[i];
            rightMax[i] = Math.max(rightSum[i], rightMax[i + 1]);
        }

        // 2 intervals
        int leftSum = 0;
        for (int i = 0; i < n - 2; i++) {
            leftSum += A[i];
            ans = Math.max(ans, leftSum + rightMax[i + 2]);
        }

        return ans;
    }
}
