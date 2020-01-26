package cn.huang.leetcode;

/*
667. Beautiful Arrangement II

 Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1
 to n and obeys the following requirement:

Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:

Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.

Example 2:

Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.

Note:

    The n and k are in the range 1 <= k < n <= 104.

 */
public class LC_0667_BeautifulArrangement_II {
    /*
    https://blog.csdn.net/Koala_Tree/article/details/78494046
     */
    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        int l = 1, r = n;
        int i = 0;
        for (; i < k; i++) {
            if (i % 2 == 0) ans[i] = l++;
            else ans[i] = r--;
        }
        if (i % 2 == 1) {
            for (int j = l; j <= r; j++) ans[i++] = j;
        } else {
            for (int j = r; j >= l; j--) ans[i++] = j;
        }
        return ans;

    }
}
