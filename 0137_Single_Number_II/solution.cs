/*
136. Single Number II

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question
*/
using System.Linq;

public class Solution137
{
    // 可以为每个位上1的数目计数。然后将该计数%3，剩下的1肯定是单独的数字贡献的。
    public int SingleNumber(int[] nums)
    {
        var result = 0;
        for (var i = 0; i < 32; i++)
        {
            var curBits = nums.Sum(t => t >> i & 1);
            result |= (curBits % 3) << i;
        }

        return result;
    }

    public int SingleNumber_2(int[] nums)
    {
        var result = 0;
        for (var i = 0; i < 32; i++)
        {
            int count = 0;  // sum of 1 on bit i
            for (int j = 0; j < nums.Length; j++)
            {
                count += (nums[j] >> i) & 1;
            }
            result += (count % 3) << i;
        }

        return result;
    }
}
