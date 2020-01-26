/*
209. Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray 
of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.


   # http://blog.csdn.net/lisonglisonglisong/article/details/45666975
    # if total < s, extend right
    # if total >=s, extend left
*/
using System;

public class Solution209 {
    // Slid window 
    public int MinSubArrayLen(int s, int[] nums) {
        var minLength = int.MaxValue;
        var total = 0;
        for(int start = 0, end = 0; end < nums.Length; end++)             
        {                 
            total += nums[end];                 
            while(total >= s && start <= end)
            {
                minLength = Math.Min(minLength, end - start + 1);
                total -= nums[start++];
            }
        }
        return minLength == int.MaxValue ? 0 : minLength;
    }

    public int MinSubArrayLen2(int s, int[] nums) {
        int len = nums.Length;
        if (len == 0)
            return 0;
        int left =0, right=0, total = 0;
        int result = len +1;
        while (right < len){
            while(right < len && total < s)
            {
                total += nums[right];
                right ++;
            }
            if (total < s)
                break;
            while(left < right && total >=s)
            {
                total -= nums[left];
                left +=1;
            }
            result = Math.Min(result, right - left +1);
        }
        if (result == len +1)
            return 0;
        return result;
    }
}