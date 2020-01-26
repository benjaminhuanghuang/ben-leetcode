package cn.huang.leetcode;

/*
55. Jump Game [45]
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.


 */
public class LC_0055_JumpGame {
    /*
    check the last index to see if front index can jump to it.
     */
    public boolean canJump(int[] nums) {
        int index = nums.length - 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] + i >= index) {
                index = i;
            }
        }

        return index <= 0;
    }


    public boolean CanJump_2(int[] nums) {
        int maxReach = nums[0];
        for (int i = 0; i <= maxReach; i++) {
            if (i >= nums.length - 1)
                return true;
            maxReach = Math.max(maxReach, nums[i] + i);
        }

        return false;
    }

    /*
    https://www.youtube.com/watch?v=r3pZd9ghqxk
     */
    public boolean CanJump_3(int[] nums) {
        if (nums == null || nums.length < 2)
            return false;

        int maxReach = 0;
        for (int i = 0; i < nums.length && i <= maxReach; i++) {
            maxReach = Math.max(maxReach, nums[i] + i);
            if (maxReach >= nums.length - 1)
                return true;
        }

        return false;
    }
}
