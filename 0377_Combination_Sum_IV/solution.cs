/*
377. Combination Sum IV
# 322 Coin Change

Given an integer array with all positive numbers and no duplicates, find the number of possible 
combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?


http://www.cnblogs.com/grandyang/p/5705750.html
开始想当然的一位还是用递归来解，结果写出来发现TLE了
*/

public class Solution377
{
    //dp[i] += dp[i-num]
    //or dp[i+num] += dp[i]
    // 状态转移方程：dp[x + y] += dp[x]
    public int CombinationSum4(int[] nums, int target)
    {
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            foreach (int num in nums)
            {
                if (i >= num)
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
}