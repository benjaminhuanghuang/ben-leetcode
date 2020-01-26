package cn.huang.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
823. Binary Trees With Factors
Given an array of unique integers, each integer is strictly greater than 1.

We make a binary tree using these integers and each number may be used for any number of times.

Each non-leaf node's value should be equal to the product of the values of it's children.

How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.

Example 1:

Input: A = [2, 4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:

Input: A = [2, 4, 5, 10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].



Note:

    1 <= A.length <= 1000.
    2 <= A[i] <= 10 ^ 9.


 */
public class LC_0823_BinaryTreesWithFactors {
    /*
    dp[c] = num of trees rooted at c
    dp[c] = sum {dp[a] * dp[b]} (c = a * b)
    ans = sum(dp[c]

    Time complexity O(n^2) Space complexity O(n)
     */
    public int numFactoredBinaryTrees(int[] A) {
        int MOD = 1_000_000_007;
        Arrays.sort(A);
        long[] dp = new long[A.length];
        Arrays.fill(dp, 1);

        Map<Integer, Integer> index = new HashMap();
        for (int i = 0; i < A.length; ++i)
            index.put(A[i], i);

        for (int i = 0; i < A.length; ++i)
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) { // A[j] is left child
                    int right = A[i] / A[j];
                    if (index.containsKey(right)) {
                        dp[i] = (dp[i] + dp[j] * dp[index.get(right)]);
                    }
                }
            }

        long ans = 0;
        for (long x : dp)
            ans += x;
        return (int) (ans % MOD);
    }
}
