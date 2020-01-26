package cn.huang.leetcode;

import java.util.Stack;

/*
84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find
the area of largest rectangle in the histogram.



Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10


 */

/*

https://www.cnblogs.com/gtarcoder/p/4550269.html


https://segmentfault.com/a/1190000003946392
要找到包含某个bar的最大矩形，只需要找到高度小于该bar的左、右边界即可，
问题变为“对于给定的bar，如何确定高度比它小的左、右边界”。最直接的思路是对于每个bar，扫面其前面所有的bar，找出最后一个高度小于它的bar，这样的话时间复杂度是N^2。

用栈维护一个高度递增的bar的集合，也就是说栈底到栈顶部对应的bar的高度越来越大。
对应一个刚读入的bar，我们只需要比较它的高度和栈顶对应bar的高度，如果当前bar比较高，则弹出栈顶元素继续比较，直到栈顶bar比它低或者栈为空。之后，将当前bar入栈，更新栈内的递增序列。

我们从左到右扫一遍得到每个bar对应的左边界，然后从右到左扫一遍得到bar的右边界。两次扫描过程中，每个bar都只有出栈、入栈操作，所以时间复杂度为O(N)。
通过这样的预处理，即可以O(N)的时间复杂度得到每个bar的左右边界。之后对于每个bar求出包含它的最大面积，也即是由左右边界和bar的高度围起来的矩形的面积。再做N次比较，即可得出最终的结果。
 */

public class LC_0084_LargestRectangleinHistogram {
    /*
    https://www.youtube.com/watch?v=TH9UaZ6JGcA

    单调栈的维护是 O(n) 级的时间复杂度，因为所有元素只会进入栈一次，并且出栈后再也不会进栈了。
     */
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0)
            return 0;

        Stack<Integer> stack = new Stack<>();
        int res = 0;
        for (int i = 0; i <= heights.length; i++)   // add 0 determine the end
        {
            int h = i == heights.length ? 0 : heights[i]; // add 0 determine the end
            while (!stack.isEmpty() && h < heights[stack.peek()]) {
                int height = heights[stack.pop()];
                int start = stack.isEmpty() ? -1 : stack.peek();
                int area = height * (i - start - 1);
                res = Math.max(res, area);
            }
            stack.push(i);
        }
        return res;
    }
}
