package cn.huang.leetcode;

import java.util.HashMap;

/*

260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear
exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]

Note:

    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

 */
public class LC_0260_SingleNumber_III {
    public int[] singleNumber(int[] nums) {
        HashMap<Integer, Integer> numbers = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            if( numbers.containsKey(nums[i]) == false ) {
                numbers.put(nums[i], 1);
            } else {
                numbers.remove(nums[i]);
            }
        }

        int[] target = new int[numbers.size()];
        int i = 0;
        for (Integer key : numbers.keySet()) {
            target[i] = key.intValue();
            i++;
        }

        return target;
    }
}
