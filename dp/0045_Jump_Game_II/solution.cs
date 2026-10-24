using System;

public class Solution045 {
    public int Jump(int[] nums)
    {
        var numberOfJump = 0;
        var previous = 0;
        var maxCanJump = previous;

        while (maxCanJump < nums.Length - 1)
        {
            for (int i = previous, maxJump = maxCanJump; i <= maxJump; i++)                 
            {                     
                if (i + nums[i] > maxCanJump)
                {
                    maxCanJump = i + nums[i];
                    previous = i;
                }
            }

            numberOfJump++;
        }

        return numberOfJump;
    }

    public int Jump_3(int[] nums) {
        var step = 0;
        var currReach = 0; // 当前能跳到的最远距离
        var lastReach = 0; // 上次最远可以跳到的距离
        for (int i = 0; i < nums.Length; i++)
        {
            Console.WriteLine("currReach = {0}, lastReach = {1}", currReach, lastReach);
            if (lastReach < i)
            {
                //lastReach < i , 说明跳上一次不到i，需要last++
                step++;
                lastReach = currReach;
            }
            //
            currReach = Math.Max(nums[i] + i, currReach);
            
        }
        return step;
    }
}