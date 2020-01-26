package cn.huang.leetcode;
/*
473. Matchsticks to Square

Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please
find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can
link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be
true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:

Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:

Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.

Note:

    The length sum of the given matchsticks is in the range of 0 to 10^9.
    The length of the given matchstick array will not exceed 15.

 */

/*
一堆长度不等的火柴，希望拼成一个正方形，不知道可以不可以？
1、用了所有火柴，一根不多，一根不少，当然一根用一次
2、四条边长度一样
 */
public class LC_0473_MatchstickstoSquare {
    public boolean makesquare(int[] nums) {
        if (nums == null || nums.length < 4) return false;
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 4 != 0)
            return false;
        return dfs(nums, new int[4], 0, sum / 4);
    }

    private boolean dfs(int[] nums, int[] sums, int index, int target) {
        if (index == nums.length) {
            if (sums[0] == target && sums[1] == target && sums[2] == target)
                return true;
            return true;
        }
        for (int i = 0; i < 4; i++) {
            if (sums[i] + nums[index] <= target) {
                sums[i] += nums[index];
                if (dfs(nums, sums, index + 1, target)) return true;
                sums[i] -= nums[index];
            }
        }
        return false;
    }
}
