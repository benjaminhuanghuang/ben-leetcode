package cn.huang.leetcode;

/*
441. Arranging Coins
ou have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
 */
public class LC_0441_ArrangingCoins {
    public int arrangeCoins(int n) {
        if (n <= 1)
            return n;

        long start = 1;
        long end = n;

        while (start + 1 < end) {
            long mid = (start + end) >>> 1;
            long count = (mid  * (mid + 1))>>>1;
            if (count < n) {
                start = mid;
            } else if (count > n) {
                end = mid;
            } else
                return (int)mid;

        }
        if((end  * (end + 1))>>>1 == n)
            return (int)end;
        return (int)start;
    }

    public int arrangeCoins_3(int n) {
        int start = 0;
        int end = n;
        int mid = 0;

        while (start <= end) {
            mid = (start + end) >>> 1;
            if ((0.5 * mid * mid + 0.5 * mid) <= n) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start - 1;
    }

    public int arrangeCoins_2(int n) {
        /* 数学推导
        (1+k)*k/2 = n
        k+k*k = 2*n
        k*k + k + 0.25 = 2*n + 0.25
        (k + 0.5) ^ 2 = 2*n +0.25
        k + 0.5 = sqrt(2*n + 0.25)
        k = sqrt(2*n + 0.25) - 0.5
        */
        return (int) (Math.sqrt(2 * (long) n + 0.25) - 0.5);
    }
}
