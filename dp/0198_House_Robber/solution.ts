/*
198. House Robber

https://leetcode.com/problems/house-robber/
*/

/*
每一间房子都在问： “偷我，还是继承昨天的成果？”
*/
function rob(nums: number[]): number {
  if (nums.length === 0) return 0;

  const dp: number[] = new Array(nums.length);
  dp[0] = nums[0];
  if (nums.length === 1) return dp[0];

  dp[1] = Math.max(nums[0], nums[1]);
  if (nums.length === 2) return dp[1];

  for (let i = 2; i < nums.length; i++) {
    // dp[i - 1] means not robbing the current house,
    // dp[i - 2] + nums[i] means robbing the current house and the i - 2 house.
    dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
  }

  return dp[nums.length - 1];
}
