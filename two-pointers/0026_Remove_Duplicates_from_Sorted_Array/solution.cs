using System;

public class Solution026
{
    public int RemoveDuplicates(int[] nums)
    {
        if (nums == null)
            return 0;
        int len = nums.Length;
        if (len < 2)
            return len;
        int pivot = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[pivot] != nums[i])
            {
                pivot++;
                nums[pivot] = nums[i];
            }
            // nums[curr] == nums[i],  i++
        }
        return pivot + 1;
    }
}