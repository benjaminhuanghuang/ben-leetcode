using System;

public class Solution312 {
    // 状态转移方程：
    // dp[l][r] = max(dp[l][r], nums[l] * nums[m] * nums[r] + dp[l][m] + dp[m][r])
    // dp[l][r]表示扎破(l, r)范围内所有气球获得的最大硬币数，不含边界；
    // l与r的跨度k从2开始逐渐增大；
    public int MaxCoins(int[] nums) {
        int[] nums2 = new int[nums.Length + 2];
        int n = 1;
        foreach (int x in nums) 
            if (x > 0) 
                nums2[n++] = x;
        nums2[0] = nums2[n++] = 1;
        
        int[][] dp = new int[n][];
        for (int i=0; i< n; i++)
            dp[i] = new int[n];

        for (int k = 2; k < n; ++k)
            for (int l = 0; l < n - k; ++l) {
                int r = l + k;
                for (int m = l + 1; m < r; ++m)
                    dp[l][r] = Math.Max(dp[l][r], 
                        nums2[l] * nums2[m] * nums2[r] + dp[l][m] + dp[m][r]);
            }
    
        return dp[0][n - 1];
    }
}