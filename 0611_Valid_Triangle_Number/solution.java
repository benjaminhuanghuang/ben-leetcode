package cn.huang.leetcode;

import java.util.Arrays;

/*
611. Valid Triangle Number
Given an array consists of non-negative integers, your task is to moves the number of triplets chosen from the array
that can make triangles if we take them as side lengths of a triangle.

Example 1:

Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Note:

    The length of the given array won't exceed 1000.
    The integers in the given array are in the range of [0, 1000].

 */
public class LC_0611_ValidTriangleNumber {
    /*
    三角形的性质:任意两条边之和要大于第三边。问题变成了找出所有这样的三个数字，使得任意两个数字之和都大于第三个数字。
    可以转变一下，三个数字中如果较小的两个数字之和大于第三个数字，那么任意两个数字之和都大于第三个数字，因为第三个数字是最大的，所以它加上任意一个数肯定大于另一个数。

    先要给数组排序，先确定前两个数，将这两个数之和sum作为目标值，然后用二分查找法来快速确定第一个小于目标值的数，
     */
    public int triangleNumber(int[] nums) {
        int res = 0, n = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j], left = j + 1, right = n;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum)
                        left = mid + 1;
                    else
                        right = mid;
                }
                res += right - 1 - j;
            }
        }
        return res;
    }
}
