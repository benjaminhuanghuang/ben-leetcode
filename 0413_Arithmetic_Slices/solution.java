package cn.huang.leetcode;

/*
    413. Arithmetic Slices

    A sequence of number is called arithmetic if it consists of at least three elements and if the difference between
    any two consecutive elements is the same.


 */
public class LC_0413_ArithmeticSlices {
    /*
        dp[i]表示，到i位置为止的算数切片的个数，
        从第三个数字开始遍历，如果当前数字和之前两个数字构成算数切片，那么我们更新dp[i]为dp[i-1]+1，然后res累加上dp[i]的值即可：
     */
    public int numberOfArithmeticSlices_DP(int[] A) {
        int res = 0, n = A.length;
        int[] dp = new int[n];

        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            res += dp[i];
        }
        return res;
    }
    //用一个变量来代替上面的数组
    public int numberOfArithmeticSlices_DP2(int[] A) {
        int result = 0;
        int curr = 0;

        for (int i = 2; i < A.length; i++) {

            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                curr += 1;
            } else {
                curr = 0;
            }
            result += curr;
        }

        return result;
    }
}
