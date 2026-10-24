package cn.huang.leetcode;
/*
    136. Single Number
 */
public class LC_0136_SingleNumber {
    public int singleNumber(int[] nums) {
        int sum = 0;
        for(int i =0; i < nums.length ; i++)
        {
            sum = sum ^ nums[i];
        }
        return sum;
    }
}
