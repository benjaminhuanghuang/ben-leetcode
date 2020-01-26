package cn.huang.leetcode;

/*
740. Delete and Earn
 Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points.
After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:

Input: nums = [3, 4, 2]
Output: 6
Explanation:
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Example 2:

Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation:
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.

Note:
The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
 */

/*
    http://www.morecoder.com/article/1066115.html
    挑选任意数字nums[i]，得到nums[i]分，同时需要删除所有等于nums[i] - 1和nums[i] + 1的整数。

    求最大得分。

    https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-740-delete-and-earn/
*/

public class LC_0740_DeleteandEarn {
    public int deleteAndEarn(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;

        int[] freq = new int[10001];
        for (int num : nums)
            freq[num]++;
        int dp1 = freq[0] * 0;
        int dp2 = Math.max(dp1, freq[1]*1);
        int dp = dp2;
        for (int i = 2; i < 10001; i++) {
            dp = Math.max(dp1 + freq[i] * i, dp2);
            dp1 = dp2;
            dp2 = dp;
        }
        return dp;
    }
}
