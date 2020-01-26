package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Stack;

/*
85. Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6


 */
public class LC_0085_MaximalRectangle {
    /*
        https://www.youtube.com/watch?v=5CEBM_174e0
        left[]   从左到右，出现连续1的string的第一个index
        right[]   从左到右，出现连续1的string的最后一个index
        height[]   从上到下，出现连续1的string的第一个index
     */
    public int maximalRectangle_dp(char[][] matrix) {
        int m = matrix.length;
        if (m == 0) return 0;
        int n = matrix[0].length;

        int[] height = new int[n];
        int[] left = new int[n];
        int[] right = new int[n];

        int res = 0;
        Arrays.fill(right, n);

        for (int i = 0; i < m; i++) {
            int currLeft = 0, currRight = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = Math.max(currLeft, left[j]);
                else {
                    left[j] = 0;
                    currLeft = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = Math.min(currRight, right[j]);
                else {
                    right[j] = n;
                    currRight = j;
                }
            }
            for (int j = 0; j < n; j++) {
                res = Math.max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }

    /*
    maintain a stack for height
     */
    public int maximalRectangle_stack(char[][] matrix) {
        if (matrix == null || matrix.length == 0)
            return 0;
        int n = matrix[0].length;
        int[] height = new int[n + 1];
        height[n] = 0;
        int res = 0;

        for (int row = 0; row < matrix.length; row++) {
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < n + 1; i++) {
                if (i < n) {
                    if (matrix[row][i] == '1') {
                        height[i]++;
                    } else {
                        height[i] = 0;
                    }
                }
                if (stack.isEmpty() || height[stack.peek()] <= height[i]) {
                    stack.push(i);
                } else {
                    while (!stack.isEmpty() && height[i] < height[stack.peek()]) {
                        int h = stack.pop();
                        int cur = height[h] * (stack.isEmpty() ? i : (i - stack.peek() - 1));
                        res = Math.max(res, cur);
                    }
                    stack.push(i);
                }
            }
        }
        return res;
    }
}
