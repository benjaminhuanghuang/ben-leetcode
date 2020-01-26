package cn.huang.leetcode;

/*
923. 3Sum With Multiplicity

Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.



Example 1:

Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation:
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

Example 2:

Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation:
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.



Note:

    3 <= A.length <= 3000
    0 <= A[i] <= 100
    0 <= target <= 300

 */
public class LC_0923_3SumWithMultiplicity {
    public int threeSumMulti(int[] A, int target) {
        int MOD = 1_000_000_007; // 因为最大数为10^9+7

        // 计算数组中不同元素出现的个数   因为 0 <= A[i] <=100
        long[] c = new long[101]; // 定义成long，在计算中不用转换
        for (int a : A) c[a]++;

        long ans = 0;
        for (int i = 0; i <= target; i++) {
            for (int j = i; j <= target; j++) {
                int k = target - i - j;
                if (k < 0 || k >= c.length || k < j)
                    continue;
                if (c[i] == 0 || c[j] == 0 || c[k] == 0)
                    continue;
                if (i == j && j == k) {
                    ans += (c[i] - 2) * (c[i] - 1) * c[i] / 6;
                } else if (i == j && j != k) {
                    ans += c[i] * (c[i] - 1) / 2 * c[k];
                } else if (i != j && j == k) {
                    ans += c[i] * (c[j] - 1) * c[j] / 2;
                } else {
                    ans += c[i] * c[j] * c[k];
                }
                ans %= MOD;
            }
        }
        return (int) ans;
    }
}
