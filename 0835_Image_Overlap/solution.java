package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/*
835. Image Overlap [Google]

Two images A and B are given, represented as binary, square matrices of the same size.
(A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units),
and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.

Notes:

    1 <= A.length = A[0].length = B.length = B[0].length <= 30
    0 <= A[i][j], B[i][j] <= 1


 */
/*
两个形状相同的正方形矩阵，求用什么体位把它两个重叠在一起，然后重叠部分中1的个数最多。
解题方法

思路挺好玩的，直接找出所有1的位置，然后对两个矩阵的所有这些位置进行求差。然后统计这些差出现最多的次数是多少。

两个坐标的差是什么含义？就是把其中一个坐标移动到另一个坐标需要移动的向量。因此，在遍历过程中，
我们找出了A中所有值为1的坐标移动到B中所有值为1的坐标需要移动的向量。那么，在这些向量中出现次数最多的向量就是我们要求的整个矩阵应该移动的向量。
这个向量出现的次数，就是我们向该向量方向移动了之后，能重叠的1的个数。

 */
public class LC_0835_ImageOverlap {
    public int largestOverlap(int[][] A, int[][] B) {
        int max = 0;
        int n = A.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(max, Math.max(getOverlap(A, B, i, j), getOverlap(B, A, i, j)));
            }
        }

        return max;
    }

    private int getOverlap(int[][] A, int[][] B, int rowOffset, int colOffset) {
        int sum = 0;
        int n = A.length;

        for (int i = rowOffset; i < n; i++) {
            for (int j = colOffset; j < n; j++) {
                sum += A[i][j] * B[i - rowOffset][j - colOffset];
            }
        }

        return sum;
    }
}
