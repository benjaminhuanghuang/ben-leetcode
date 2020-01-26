package cn.huang.leetcode;

import java.util.TreeSet;

/*
363. Max Sum of Rectangle No Larger Than K

Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its
sum is no larger than k.

Example:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).

Note:

    The rectangle inside the matrix must have an area > 0.
    What if the number of rows is much larger than the number of columns?


 */
public class LC_0363_MaxSumofRectangleNoLargerThanK {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }

        int max = Integer.MIN_VALUE;
        int m = matrix.length;
        int n = matrix[0].length;
        for (int i = 0; i < n; i++) {
            int[] sum = new int[m];
            for (int j = i; j < n; j++) {
                for (int p = 0; p < m; p++) {
                    sum[p] += matrix[p][j];
                }

                int cum = 0;
                TreeSet<Integer> set = new TreeSet<Integer>();
                set.add(0);
                for (int p = 0; p < m; p++) {
                    cum += sum[p];
                    Integer value = set.ceiling(cum - k);
                    if (value != null) {
                        if (max < cum - value) {
                            max = cum - value;
                        }
                    }
                    set.add(cum);
                }
            }
        }

        return max;
    }
}
