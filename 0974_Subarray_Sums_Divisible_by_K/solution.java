package cn.huang.leetcode;

/*
974. Subarray Sums Divisible by K

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.



Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]



Note:

    1 <= A.length <= 30000
    -10000 <= A[i] <= 10000
    2 <= K <= 10000


 */
public class LC_0974_SubarraySumsDivisiblebyK {
    public int subarraysDivByK(int[] A, int K) {
        int len = A.length;
        int[] prefixSum = new int[len + 1];
        for (int i = 0; i < len; ++i)
            prefixSum[i + 1] = prefixSum[i] + A[i];

        int[] count = new int[K];
        for (int x : prefixSum)
            count[(x % K + K) % K]++;

        int ans = 0;
        for (int v : count)
            ans += v * (v - 1) / 2;
        return ans;
    }

    /*
    https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-974-subarray-sums-divisible-by-k/
    let c[i] denotes the counts of prefix_sum % K init: c[0] = 1
    Whenever we end up with the same prefix sum (after modulo), which means there are subarrys end with current
    element that is divisible by K (0 modulo).

    e.g. A = [4,5,0,-2,-3,1], K = 5
    [4,5] has prefix sum of 4, which happens at index 0 [4], and index 1, [4,5]
    [4,5,0] also has a prefix sum of 4, which means [4, {5,0}], [4,5, {0}] are divisible by K.

    ans += (c[prefix_sum] – 1)
    i = 0, prefix_sum = 0, c[(0+4)%5] = c[4] = 1, ans = 0
    i = 1, prefix_sum = 4+5, c[(4+5)%5] = c[4] = 2, ans = 0+2-1=0 => [5]
    i = 2, prefix_sum = 4+0, c[(4+0)%5] = c[4] = 3, ans = 1+3-1=3 => [5], [5,0], [0]
    i = 3, prefix_sum = 4-2, c[(4-2)%5] = c[2] = 1, ans = 3
    i = 4, prefix_sum = 2-3, c[(2-3+5)%5] = c[4] = 4, ans = 3+4-1=6 => [5],[5,0],[0],[5,0,-2,-3], [0,-2,-3],[-2,-3]
    i = 5, prefix_sum = 4+1, c[(4+1)%5] = c[0] = 2, ans = 6 + 2 – 1 =>
    [5],[5,0],[0],[5,0,-2,-3], [0,-2,-3],[-2,-3], [4,5,0,-2,-3,1]

    Time complexity: O(n)
    Space complexity: O(n)
     */
    public int subarraysDivByK2(int[] A, int K) {
        int[] c = new int[K];
        c[0] = 1;
        int ans = 0;
        int sum = 0;
        for (int a : A) {
            sum = (sum + a % K + K) % K;
            ans += c[sum]++;
        }
        return ans;
    }
}
