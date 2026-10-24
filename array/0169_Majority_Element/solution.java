package cn.huang.leetcode;

/*
    169. Majority Element
    Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority element always exist in the array.

    Example 1:

    Input: [3,2,3]
    Output: 3
    Example 2:

    Input: [2,2,1,1,1,2,2]
    Output: 2
 */
public class LC_0169_MajorityElement {
    /*
        majority element is the element that appears more than  n/2
        用一个标记cnt记录某个元素出现的次数，如果后面的元素和它相同就加一，有一个元素和他不相同就减一，当cnt小于等于0时重新记录新的元素。
     */
    public int majorityElement(int[] nums) {
        int main = nums[0];
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (main == nums[i]) {
                count++; //
            } else {
                if (count > 0) {
                    count--;
                } else {
                    main = nums[i];
                }
            }
        }
        return main;
    }
}
