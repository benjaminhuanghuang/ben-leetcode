/*
494. Target Sum

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 
symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
 */


public class Solution494
{
    private int count = 0;
    public int FindTargetSumWays(int[] nums, int S)
    {
        helper(nums, 0, S);
        return count;
    }

    private void helper(int[] nums, int cur, int target)
    {
        if (cur == nums.Length)
        {
            if (target == 0)
            {
                ++count;
            }
            return;
        }
        helper(nums, cur + 1, target + nums[cur]);
        helper(nums, cur + 1, target - nums[cur]);
    }
}