package cn.huang.leetcode;
/*
213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two
adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount
of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.



 */
public class LC_0213_HouseRobber_II {
    public int rob(int[] nums) {
        if(nums.length == 1)
            return nums[0];
        // skip first one;
        int max1 = this.MaxRob(nums, 1, nums.length -1);
        // skip last one
        int max2 = this.MaxRob(nums, 0, nums.length -2);

        return Math.max(max1, max2);
    }

    public int MaxRob(int[] nums, int start, int end)
    {
        int count = 1;
        int sumOdd = 0;
        int sumEven = 0;
        for(int i = start; i <= end; i++, count++)
        {
            if(count %2 ==1)
                sumOdd = Math.max(sumOdd + nums[i], sumEven);
            if(count %2 ==0)
                sumEven = Math.max(sumEven + nums[i], sumOdd);
        }
        return Math.max(sumOdd, sumEven);
    }
}
