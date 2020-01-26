'''
85. Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 6.
'''


# http://www.jianshu.com/p/cffdc94c9c19
class Solution(object):
    # https://www.tianmaying.com/tutorial/LC85
    # https://yq.aliyun.com/articles/3496
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        res = 0
        if not matrix:
            return res
        height = [0 for i in range(len(matrix[0]))]
        for row in matrix:
            for i in range(len(row)):
                if row[i] == '0':
                    height[i] = 0
                else:
                    height[i] += 1
            res = max(res, self.largestRectangleArea(height))

        return res

    def largestRectangleArea(self, height):
        if not height:
            return 0

        res = 0
        stack = []
        height.append(-1)
        for i in range(len(height)):
            current = height[i]
            while len(stack) != 0 and current <= height[stack[-1]]:
                h = height[stack.pop()]
                w = i if len(stack) == 0 else i - stack[-1] - 1
                res = max(res, h * w)
            stack.append(i)
        return res
