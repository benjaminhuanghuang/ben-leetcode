/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

https://miafish.wordpress.com/2015/04/08/leetcode-ojc-trapping-rain-water/
*/
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution042 {
    public int Trap_Stack(int[] height) {
        var res = 0;
        var stack = new Stack<int>();
        var max = 0;

        for (int i =0; i < height.Length; i++)
        {
            while(stack.Any() && height[i]>max)
            {
                var top = stack.Pop();
                res += max - height[top];
            }
            stack.Push(i);
            max = Math.Max(max, height[i]);
        }
        var curMax = stack.Any() ? height[stack.Peek()] : 0;
        while (stack.Any())
        {
            var top = stack.Pop();
            if (curMax <= height[top])
            {
                curMax = height[top];
            }
            else
            {
                res += curMax - height[top];
            }
        }
        return res;
    }


    // find max hight and its index.
    // move left pointer from 0 to max index, right pointer from len – 1 to max index
    public int Trap_MaxHeight(int[] height)
    {
        var res = 0;
        var max = 0;
        var maxindex = -1;
        
        if(height.Length <=1)
            return 0;
        
        for (int i = 0; i < height.Length; i++)             
        {                 
            if (height[i] > max)
            {
                max = height[i];
                maxindex = i;
            }
        }

        var leftmax = 0;
        for (int i = 0; i < maxindex; i++)             
        {                 
            leftmax = Math.Max(leftmax, height[i]);                 
            res += leftmax - height[i];             
        }             
        var rightmax = 0;             
        for (int i = height.Length - 1; i >= maxindex; i--)
        {
            rightmax = Math.Max(rightmax, height[i]);
            res += rightmax - height[i];
        }

        return res;
    }
    // https://www.hrwhisper.me/leetcode-trapping-rain-water/
    // http://www.lxway.net/898969464.html
    public int Trap_MaxHeight_2(int[] height)
    {
        var res = 0;
        var max = 0;
        var left = 0;
        var right = height.Length - 1;

        while (left <= right)
        {
            if (height[left] < height[right])
            {
                max = Math.Max(max, height[left]);
                res += max - height[left];
                left++;
            }
            else
            {
                max = Math.Max(max, height[right]);
                res += max - height[right];
                right--;
            }
        }

        return res;
    }
}