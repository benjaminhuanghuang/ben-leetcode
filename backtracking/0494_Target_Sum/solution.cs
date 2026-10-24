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