package cn.huang.leetcode;
/*
932. Beautiful Array

For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)



Example 1:

Input: 4
Output: [2,1,4,3]

Example 2:

Input: 5
Output: [3,1,2,5,4]



Note:

    1 <= N <= 1000

 */

import java.util.HashMap;
import java.util.Map;

/*
i 和 j的平均数不在 i 和 j之间
https://www.jianshu.com/p/6b9dc1ecdf1d
 */
public class LC_0932_BeautifulArray {
    Map<Integer, int[]> memo;

    public int[] beautifulArray(int N) {
        memo = new HashMap();
        return f(N);
    }

    public int[] f(int N) {
        if (memo.containsKey(N))
            return memo.get(N);

        int[] ans = new int[N];
        if (N == 1) {
            ans[0] = 1;
        } else {
            int t = 0;
            for (int x : f((N + 1) / 2))  // 奇数
                ans[t++] = 2 * x - 1;
            for (int x : f(N / 2))  // 偶数
                ans[t++] = 2 * x;
        }
        memo.put(N, ans);
        return ans;
    }
}
