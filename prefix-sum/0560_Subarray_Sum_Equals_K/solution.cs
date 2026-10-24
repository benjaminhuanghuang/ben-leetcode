/*
560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous 
subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 
 */

/*
本题需要注意的是可能存在负数。首先第一种方法暴力搜索法，两个循环，但是由于负数的存在不能在碰到一个之后就break：
 */

using System;
using System.Collections.Generic;

public class Solution560
{
    public int SubarraySum(int[] nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            int sum = nums[i];
            if (sum == k)
            {
                count++;
            }
            for (int j = i + 1; j < nums.Length; j++)
            {
                sum += nums[j];
                // 但是由于负数的存在不能在碰到一个之后就break：
                if (sum == k)
                    count++;
            }
        }
        return count;
    }

    public int SubarraySum2(int[] nums, int k)
    {
        int sum = 0, count = 0;
        Dictionary<int, int> map = new Dictionary<int, int>();
        map[0] = 1;
        for (int i = 0; i < nums.Length; i++)
        {
            sum += nums[i];
            if (map.ContainsKey(sum - k))
                count += map[sum - k];
            if(!map.ContainsKey(sum))
                map[sum] = 0;    
            map[sum] = map[sum] + 1;
        }
        return count;
    }
}

