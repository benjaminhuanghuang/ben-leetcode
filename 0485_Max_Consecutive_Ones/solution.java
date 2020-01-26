package cn.huang.leetcode;

/*
    485. Max Consecutive Ones
    Given a binary array, find the maximum number of consecutive 1s in this array.

    Example 1:
    Input: [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s.
        The maximum number of consecutive 1s is 3.

 */
public class LC_0485_MaxConsecutiveOnes {
    public int findMaxConsecutiveOnes(int[] nums) {
        if (nums == null)
            return 0;

        int maxNum = 0;
        int count = -1;

        for (int i = 0; i < nums.length; i++) {
            if(nums[i] == 1)
            {
                if(count == -1)
                {
                    count =1;
                }
                else
                {
                    count ++;
                }
            }
            else
            {
                if(count > 0)
                {
                    maxNum = Math.max(maxNum, count);
                    count = -1;
                }
            }
        }
        maxNum = Math.max(maxNum, count);  // the last number is 1
        return maxNum;
    }
}
