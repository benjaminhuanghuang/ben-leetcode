package cn.huang.leetcode;

/*
    643. Maximum Average Subarray I
 */
public class LC_0643_MaximumAverageSubarray_I {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        int begin = 0;
        int end = k;

        for (; end < nums.length; end++) {
            sum -= nums[begin];
            sum += nums[end];
            begin++;
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        return (double) maxSum / k;
    }
}
