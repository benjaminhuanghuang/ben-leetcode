using System;

public class Solution169 {
    public int MajorityElement(int[] nums) {
        Array.Sort(nums);
        return nums[nums.Length/2];
    }

    public int MajorityElement_2(int[] nums) {
        int previous = nums[0];
        int count = 1;
        
        for (int i = 1; i < nums.Length; i++)
        {
            if (count == 0)
            {
                previous = nums[i];
            }

            if (nums[i] == previous)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return previous;
    }
}

