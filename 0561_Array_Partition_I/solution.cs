using System;
public class Solution561
{
    public int ArrayPairSum(int[] nums)
    {
        if (nums == null || nums.Length == 0)
            return 0;
        Array.Sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (i % 2 == 0)
            {
                sum += nums[i];
            }
        }
        return sum;
    }
}