/*
53. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the 
largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/


public class Solution053 {
    // DP 当前和为sum,如果sum >0,那么加上当前元素，否则sum=A[i] （即抛弃负数的sum，重新开始。因为负数的sum是累赘)
    public int MaxSubArray(int[] nums) {
        int maxSum = nums[0];
        int sum =0;
        for ( int i =0 ;i< nums.Length; i++)
        {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            if(sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
}