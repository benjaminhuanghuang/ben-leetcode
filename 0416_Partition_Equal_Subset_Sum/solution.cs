using System.Linq;

public class Solution416 {
    /*
        O(2^n)
    */
    public bool CanPartition_bruteforce(int[] nums) {
    }
    // 其中dp[i]表示数字i是否是原数组的任意个子集合之和，那么我们我们最后只需要返回dp[target]就行了。
    // 我们初始化dp[0]为true，由于题目中限制了所有数字为正数，那么我们就不用担心会出现和为0或者负数的情况。
    // 那么对于这个区间中的任意一个数字j，如果dp[j - nums[j]]为true的话，那么dp[j]就一定为true，于是地推公式如下：
    //   dp[j] = dp[j] || dp[j - nums[i]] 
    public bool CanPartition(int[] nums) {
        int sum = nums.Sum();
        if (sum % 2 != 0)
            return false;
        int target = sum /2;
        bool[] dp = new bool[target + 1];
        dp[0] = true;
        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = target; j >= nums[i]; j     --)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
}