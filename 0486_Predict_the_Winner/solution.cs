/*
两人依次拿，如果Player1赢，则Player1拿的>Player2拿的。我们把Player1拿的视为"+"，把Player2拿的视为"-"，如果最后
结果大于等于0则Player1赢。

把问题转换为两个选手所拿元素的差值。这是关键的一步。
*/

using System;
public class Solution486
{
    public bool PredictTheWinner(int[] nums)
    {
        return helper(nums, 0, nums.Length - 1) >= 0;
    }

    private int helper(int[] nums, int start, int end)
    {
        if (start == end)
        {
            //如果只剩一个元素，player1能拿到的分数就是这个元素,player2能拿到分数为0，两人分数差为0
            return nums[start];   
        }
        else
        {
            //player1 与 player2的分数之差
            return Math.Max(nums[start] - helper(nums, start + 1, end), nums[end] - helper(nums, start, end - 1));
        }
    }
}