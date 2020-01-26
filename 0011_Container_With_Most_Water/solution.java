package cn.huang.leetcode;
/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical
lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

 */


/*
    // http://www.cnblogs.com/allzy/p/5068216.html
    // area(i,j) = min(ai, aj) * (j-i)
    // if left_height < right_height, move left_heigt from left to right,
    // if left_height > right_height, move right_heigt from right to left

 */
public class LC_0011_ContainerWithMostWater {
    public int maxArea(int[] height) {
        if (height.length < 2)
            return 0;

        int ans = 0, l = 0, r = height.length - 1;

        while (l < r)
        {
            int area = (r - l) * Math.min(height[l] , height[r]);
            ans = Math.max(area, ans);
            // 当height[l] < height[r]时，moving r can not create more volume.
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
}
