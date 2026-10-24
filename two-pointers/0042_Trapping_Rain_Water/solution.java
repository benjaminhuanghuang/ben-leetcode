package cn.huang.leetcode;

/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
(blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6


 */
public class LC_0042_TrappingRainWater {
    /*

    https://www.youtube.com/watch?v=8BHqSdwyODs
    每个位置所能存的水由 左边的最高值 和 右边的最高值 决定

    https://www.youtube.com/watch?v=2LjNzbK2cmA
    当前单元能装多少水是取决于左右两边挡板最小值与当前值之差。之后就用双指针更新左右挡板就好了。﻿

     */
    public int trap(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int res = 0;

        int leftMax = 0;
        int rightMax = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = Math.max(height[left], leftMax);
                res += leftMax - height[left];
                left++;
            } else {
                rightMax = Math.max(height[right], rightMax);
                res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }
}
