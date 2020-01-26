package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
930. Binary Subarrays With Sum

In an array A of 0s and 1s, how many non-empty subarrays have sum S?



Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation:
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]



Note:

    A.length <= 30000
    0 <= S <= A.length
    A[i] is either 0 or 1.

 */
public class LC_0930_BinarySubarraysWithSum {

    public int numSubarraysWithSum(int[] A, int S) {
        int[] prefixSum = new int[A.length + 1];
        for (int i = 0; i < A.length; i++)
            prefixSum[i + 1] = prefixSum[i] + A[i];

        Map<Integer, Integer> count = new HashMap<>();
        int ans = 0;
        for (int c : prefixSum) {
            ans += count.getOrDefault(c, 0);
            count.put(c + S, count.getOrDefault(c + S, 0) + 1);
        }
        return ans;
    }
}
