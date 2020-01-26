/*
594. Longest Harmonious Subsequence

We define a harmonious array is an array where the difference between its maximum value and its 
minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence 
among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
 */

using System;
using System.Collections.Generic;

public class Solution594
{
    public int FindLHS(int[] nums)
    {
        Dictionary<long, int> map = new Dictionary<long, int>();
        foreach (long num in nums)
        {
            if (!map.ContainsKey(num))
            {
                map[num] = 0;
            }

            map[num]++;
        }
        int result = 0;
        foreach (long key in map.Keys)
        {
            if (map.ContainsKey(key + 1))
            {
                result = Math.Max(result, map[key + 1] + map[key]);
            }
        }
        return result;
    }
}