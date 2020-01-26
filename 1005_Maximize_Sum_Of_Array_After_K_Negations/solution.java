package cn.huang.leetcode;
/*

1005. Maximize Sum Of Array After K Negations


Given an array A of integers, we must modify the array in the following way:
we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.
(We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.



Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].
Example 2:

Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
Example 3:

Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].


Note:

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
 */

import java.util.Arrays;

/*
1. 如果有负数， 那肯定是优先做负数， 而且是从最小的负数开始操作（绝对值最大的）
2. 如果负数操作的次数已经到K了， 那么就当前的操作就已经是最后的结果了
3. 如果从负数开始操作到0， 那么，剩下最好的操作一定是对0进行不停的操作直到K， 因为如果去操作正数的话会导致结果变小
4. 如果没有0， 只有正数了，还剩下x次要操作， 那么这时候有两种情况，
如果x是偶数，那么，sum保持当前状态不变，因为可以对同一个数做偶数次操作，相当于没有操作。
如果x是奇数，那么，我们要做一次操作，sum会变小，这时候，应该选绝对值最小的数， 然后剩下做偶数次操作，sum不变。
 */
public class LC_1005_MaximizeSumOfArrayAfterKNegations {
    public int largestSumAfterKNegations(int[] A, int K) {
        Arrays.sort(A);
        int sum = 0;
        for(int v: A) {
            sum += v;
        }
        int count = 0;
        int minabs = Math.abs(A[0]);
        for(int v: A) {
            minabs = Math.min(minabs, Math.abs(v));
            if(v < 0) {
                sum += 2 * Math.abs(v);
                count++;
                if(count >= K) {
                    break;
                }
            }
            else if(v == 0) {
                break;
            }
            else {
                int remain = K-count;
                if(remain%2 == 1) {
                    sum -= 2 * minabs;
                }
                break;
            }
        }
        return sum;
    }
}
