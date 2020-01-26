package cn.huang.leetcode;

/*
45. Jump Game II  [55]

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
 */

/*
https://www.youtube.com/watch?v=Vph9iepTHiA
 */
public class LC_0045_JumpGame_II {

    /*
    Greedy
     */
    public int jump(int[] nums) {
        if (nums == null || nums.length < 2)
            return 0;

        int res = 0;
        int currMaxArea = 0;  // 当前能走到的最大步数
        int maxNext = 0; // 最终能走到的最大步数

        for (int i = 0; i < nums.length - 1; i++) {  //
            maxNext = Math.max(maxNext, i + nums[i]);  // 能达到的最大步数
            if (i == currMaxArea) {
                res++;
                currMaxArea = maxNext;
            }
        }
        return res;
    }

    /*
    https://www.youtube.com/watch?v=Vph9iepTHiA
     */
    public int jump_bfs(int[] nums) {
        if (nums == null || nums.length < 2)
            return 0;

        int res = 0;

        return res;
    }

    public int Jump_2(int[] nums) {
        int ans = 0;
        int currReach = 0; // 当前能跳到的最远位置
        int lastReach = 0; // 上次最远可以跳到的位置
        for (int i = 0; i < nums.length; i++) {
            if (lastReach < i) {
                //lastReach < i , 说明跳上一次不到i，需要ans++
                ans++;
                lastReach = currReach;
            }
            //
            currReach = Math.max(nums[i] + i, currReach);

        }
        return ans;
    }

    /*
    https://www.youtube.com/watch?v=r3pZd9ghqxk
     */
    public int Jump_better(int[] nums) {
        int steps = 0;
        int currReach = 0; // 当前能跳到的最远位置
        int nextReach = 0; // 下次最远可以跳到的位置
        int i = 0;
        /*
        Take [2,1,3,1,1,1,1] as a sample. at position 0, the value is 2, we can go to position 1 (nextReach is pos 2)
        or go to position 2 (nextReach is position 5)
        */
        while (i <= currReach) {
            while (i <= currReach) {
                nextReach = Math.max(nextReach, i + nums[i]);
                i++;
            }
            currReach = nextReach;
            steps++;
            if (currReach >= nums.length - 1)
                return steps;
        }
        return steps;
    }
}
