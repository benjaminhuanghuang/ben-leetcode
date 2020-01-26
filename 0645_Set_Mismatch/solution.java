package cn.huang.leetcode;

/*
    645. Set Mismatch
    The set S originally contains numbers from 1 to n. But unfortunately, due to the data error,
    one of the numbers in the set got duplicated to another number in the set, which results
    in repetition of one number and loss of another number.

    Given an array nums representing the data status of this set after the error.
    Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

    Example 1:
    Input: nums = [1,2,2,4]
    Output: [2,3]
    Note:
    The given array size will in the range [2, 10000].
    The given array's numbers won't have any order.
 */
public class LC_0645_SetMismatch {
    public int[] findErrorNums(int[] nums) {
        int res[] = new int[2];
        //boolean类型默认初始化为false
        boolean map[] = new boolean[nums.length + 1];

        for (int i = 0; i < nums.length; i++)
            if (map[nums[i]] == false)
                map[nums[i]] = true;
            else
                res[0] = nums[i];

        for (int i = 1; i < (nums.length + 1); i++)
            if (map[i] == false) {
                res[1] = i;
                break;
            }
        return res;
    }
}
