package cn.huang.leetcode;

/*
    674. Longest Continuous Increasing Subsequence
    # 53
 */
public class LC_0674_LongestContinuousIncreasingSubsequence {
    /* DP
        if nums[i] > nums[i-1]
            dp[i] = dp[i-1] + 1
        else
            dp[i] = 1
     */
    public int findLengthOfLCIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;

        int maxlength = 1;
        int curr = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] < nums[i]) {
                curr++;
                maxlength = Math.max(curr, maxlength);
            } else {
                curr = 1;
            }
        }

        return maxlength;
    }
}
