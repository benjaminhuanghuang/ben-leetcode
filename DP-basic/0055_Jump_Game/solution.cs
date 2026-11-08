using System;

public class Solution055 {

    public bool CanJump(int[] nums) {
        var maxReach = 0;   // max index can jump to 
        for (int i =0 ; i < nums.Length; i++)
        {                 
            if (maxReach >= nums.Length - 1) 
                return true;
            if (maxReach >= i)
                maxReach = Math.Max(maxReach, nums[i] + i);
        }

        return false;
    }

    // iterative from first element, and check how far it can jump. 
    // make the jump most index as next iterative index. Use index + nums[index] 
    // to compare for jump most index.
    public bool CanJump_1(int[] nums)
    {
        var previous = 0;
        var next = 0;
        var maxCanJump = nums[previous] + previous;

        while (maxCanJump < nums.Length - 1)
        {
            for (int i = previous, maxJump = maxCanJump; i <= maxJump; i++)                 
            {                     
                if (i + nums[i] > maxCanJump)
                {
                    maxCanJump = i + nums[i];
                    next = i;
                }
            }

            if (previous == next)
            {
                return false;
            }

            previous = next;
        }

        return true;
    }
    public bool CanJump_2(int[] nums) {
        var maxJump = nums[0];
        for (int i =0 ; i <= maxJump; i++)
        {                 
            if (i >= nums.Length - 1) 
                return true;
            maxJump = Math.Max(maxJump, nums[i] + i);
        }

        return false;
    }

    //check the last index to see if front index can jump to it.
    public bool CanJump_3(int[] nums) {
        var index = nums.Length - 1;
        for (int i = nums.Length - 2; i >= 0; i--)
        {
            if (nums[i] + i >= index)
            {
                index = i;
            }
        }

        return index <= 0;       
    }
}