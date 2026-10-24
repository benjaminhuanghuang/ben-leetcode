'''
84. Largest Rectangle in Histogram [hard]

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find
the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

'''


class Solution(object):
    # http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
    # http://chaoren.is-programmer.com/posts/42674.html
    def largestRectangleArea_2(self, heights):
        stack = []
        i = 0
        maxArea = 0
        # +[0] to make sure all height can be pop up
        h = heights + [0]
        h_length = len(h)
        while i < h_length:
            # not stack means stack is empty
            if (not stack) or h[stack[-1]] <= h[i]:
                stack.append(i)
                i += 1
            else:
                t = stack.pop()
                maxArea = max(maxArea, h[t] * (i if not stack else i - stack[-1] - 1))
        return maxArea

    # Time limit exceeded.
    def largestRectangleArea_niave(self, heights):
        maxarea = 0
        for i in range(len(heights)):
            min = heights[i]
            for j in range(i, len(heights)):
                if heights[j] < min:
                    min = heights[j]
                if min * (j - i + 1) > maxarea:
                    maxarea = min * (j - i + 1)
        return maxarea


heights = [2, 1, 5, 6, 2, 3]
s = Solution()
# print s.largestRectangleArea_niave(heights)
heights = [1]

print s.largestRectangleArea_2(heights)
