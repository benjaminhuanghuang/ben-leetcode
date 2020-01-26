package cn.huang.leetcode;

/*
    747. Largest Number At Least Twice of Others
 */
public class LC_0747_LargestNumberAtLeastTwiceofOthers {
    public int dominantIndex(int[] nums) {
        int max = 0;
        int secondMax = 0;
        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max) {
                secondMax = max;
                max = nums[i];
                index = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        return max >= 2*secondMax ? index : -1;
    }
}
