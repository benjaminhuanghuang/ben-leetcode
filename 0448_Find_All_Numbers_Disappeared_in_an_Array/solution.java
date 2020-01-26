package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
    448. Find All Numbers Disappeared in an Array
    Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others
    appear once.

    Find all the elements of [1, n] inclusive that do not appear in this array.

    Could you do it without extra space and in O(n) runtime? You may assume the returned list does not moves as extra space.

    Example:

    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [5,6]
 */
public class LC_0448_FindAllNumbersDisappearedinanArray {
    /*
    数组中的数字均满足1 ≤ a[i] ≤ n，也就是说其中的元素和数组的位置索引存在某种关联性。
    如果数组中不缺少数字，那么每一个元素就会与数组的位置索引所一一对应，
    利用这种关系,遍历数组，若元素存在num[i]，则将其看作位置索引，那么就把num[i]-1位置上的元素变为负数。
    最终没有变为负数的元素所在的位置索引值，就是我们没有见过的数字。
    */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        ArrayList<Integer> ret = new ArrayList<Integer>();

        for (int i = 0; i < nums.length; i++) {
            int value = Math.abs(nums[i]) - 1;
            if (nums[value] > 0) {
                nums[value] = -nums[value];
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                ret.add(i + 1);
            }
        }

        return ret;
    }
}
