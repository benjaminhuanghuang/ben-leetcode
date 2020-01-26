/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical 
lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together 
with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
using System;

public class Solution011 {
    // http://www.cnblogs.com/allzy/p/5068216.html
    // area(i,j) = min(ai, aj) * (j-i)
    // if left_height < right_height, move left_heigt from left to right,
    // if left_height > right_height, move right_heigt from right to left  
    public int MaxArea(int[] height) {
        if (height.Length < 2) 
            return 0;

        int ans = 0, l = 0, r = height.Length - 1;

        while (l < r)
        {
            int area = (r - l) * Math.Min(height[l] , height[r]);
            ans = Math.Max(area, ans);
            if (height[l] < height[r]) 
                l++; 
            else 
                r--;
        }
        return ans;
    }
}

