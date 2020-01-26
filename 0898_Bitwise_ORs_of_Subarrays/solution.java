package cn.huang.leetcode;

import java.util.HashSet;
import java.util.Set;

/*
898. Bitwise ORs of Subarrays

We have an array A of non-negative integers.

For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the elements
in B, obtaining a result A[i] | A[i+1] | ... | A[j].

Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)



Example 1:

Input: [0]
Output: 1
Explanation:
There is only one possible result: 0.

Example 2:

Input: [1,1,2]
Output: 3
Explanation:
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

Example 3:

Input: [1,2,4]
Output: 6
Explanation:
The possible results are 1, 2, 3, 4, 6, and 7.



Note:

    1 <= A.length <= 50000
    0 <= A[i] <= 10^9


 */
public class LC_0898_BitwiseORsofSubarrays {
    public int subarrayBitwiseORs(int[] A) {
        if (A == null || A.length == 0) {
            return 0;
        }
        int len = A.length;
        // bitwise OR of subarray [i,j]
        int[] dp = new int[len];
        Set<Integer> visited = new HashSet<>();
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (i == j) {
                    dp[j] = A[i];
                } else {
                    dp[j] = A[j] | dp[j + 1];
                }
                visited.add(dp[j]);
            }
        }
        return visited.size();
    }
}
