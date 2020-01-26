package cn.huang.leetcode;
/*
560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

 */

import java.util.HashMap;
import java.util.Map;

/*
来 Offer: https://www.youtube.com/watch?v=aYfwus5T3Bs

 */
public class LC_0560_SubarraySumEqualsK
{
    /*
    Time: O(N^3) Space: O(1)
    Time limit exceeded
     */
    public int subarraySum_Naive(int[] nums, int k) {
        int count = 0;
        for(int start =0 ; start < nums.length ; start++)
        {
            for(int end = start ;end < nums.length ; end++)
            {
                int sum = 0;
                for(int i = start ;i <= end ; i++)
                {
                    sum += nums[i];
                }
                if(sum == k)
                    count++;
            }
        }
        return count;
    }

    /*
    prefixSum
    Time: O(N^2) Space: O(1)
     */
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for(int start =0 ; start < nums.length ; start++)
        {
            int prefixSum = 0;
            for(int end = start ;end < nums.length ; end++)
            {
                prefixSum += nums[end];
                if(prefixSum == k)
                    count++;
            }
        }
        return count;
    }

    /*
    prefixSum array : 用于解决和 sum of subarray 相关问题
    prefixSum[x] = sum of subArray(0, x)
                 = prefixSum[x - 1] + nums[x]
    sum of subarray(i,j) = prefixSum[j] - prefixSum[i-1]

    Time: O(N) Space: O(N)
     */
    public int subarraySum_better(int[] nums, int k) {
        if(nums == null || nums.length == 0)
            return 0;

        // 记录prefixSum出现的value和个数
        Map<Integer, Integer> sums = new HashMap<>();

        sums.put(0,1);  // important! 为了满足 prefixSum[i-1]

        int prefixSum =0;
        int count = 0;
        for(int n : nums)
        {
            prefixSum += n;
            count += sums.getOrDefault(prefixSum - k, 0);
            sums.put(prefixSum, sums.getOrDefault(prefixSum, 0) + 1 );
        }

        return count;
    }
}
