package cn.huang.leetcode;
/*
312. Burst Balloons

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right]
coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

    You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
    0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


 */

/*
打气球的游戏，每个气球都对应着一个数字，每次打爆一个气球，得到的金币数是被打爆的气球的数字和其两边的气球上的数字相乘，
如果旁边没有气球了，则按1算，以此类推，求能得到的最多金币数。

 */
public class LC_0312_BurstBalloons {
    /*
    https://www.youtube.com/watch?v=z3hu2Be92UA
     */
    public int maxCoins(int[] nums) {
        int n = nums.length + 2;
        int []a = new int[n];
        a[0] = 1;
        a[n - 1] = 1;
        for (int i = 0; i < n - 2; i ++) {
            a[i + 1] = nums[i];
        }
        int [][]dp = new int[n][n];
        for (int l = 2; l < n; l ++) {
            for (int i = 0; i + l < n; i ++) {
                int j = i + l;
                for (int k = i + 1; k < j; k ++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
