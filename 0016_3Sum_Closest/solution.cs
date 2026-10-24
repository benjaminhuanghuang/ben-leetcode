using System;

public class Solution016 {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        int res = nums[0]+ nums[1]+ nums[2];
        for (int i = 0; i < nums.Length; i++)
        {
            for (int start = i + 1, end = nums.Length - 1; start < end;)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(Math.Abs(sum - target)< Math.Abs(res - target))
                {
                    res = sum;
                    if (res == target)
                        return res;
                }
                
                if(sum <= target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        return res;
    }
}