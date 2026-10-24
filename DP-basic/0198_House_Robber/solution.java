package cn.huang.leetcode;

/*
	198	 House Robber

 */
public class LC_0198_HouseRobber {
    /*
    ，比如说nums为{3, 2, 1, 5}，
      首先dp[0]=3，
      再看dp[1]，由于3比2大，所以我们抢第一个房子的3，当前房子的2不抢，所以dp[1]=3，
      再看dp[2]，由于不能抢相邻的，所以用"再"前面的一个的dp值加上当前的房间值，和当前房间的前面一个dp值比较，取较大值当做当前dp值，
      可以得到状态转移方程dp[i] = max(num[i] + dp[i - 2], dp[i - 1]),
      初始化dp[0]和dp[1]，其中dp[0]即为num[0]，dp[1]此时应该为max(num[0], num[1])，
     */
    public int rob_dp(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;

        if (nums.length == 1)
            return nums[0];

        int[] dp = new int[nums.length];

        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);

        for (int i = 2; i < nums.length; ++i) {
            dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.length - 1];
    }

    /*

    there are two possible situation:
    1. Rob current house and previous previous house
    2. Rob previous house but not current house


     */
    public int rob_better(int[] nums) {
        int evenRob = 0, oddRob = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i % 2 == 0) {
                evenRob = Math.max(evenRob + nums[i], oddRob);
            } else {
                oddRob = Math.max(evenRob, oddRob + nums[i]);
            }
        }
        return Math.max(evenRob, oddRob);
    }
}
