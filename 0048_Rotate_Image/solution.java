package cn.huang.leetcode;

/*

48. Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]


 */
public class LC_0048_RotateImage {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int layerNum = n / 2;
        for (int layer = 0; layer < layerNum; layer++) {
            int start = layer;
            int end = n - 1 - layer;

            for (int i = start; i < end; i++) {
                int offset = i - start;
                int temp = matrix[start][i]; // back the up layer
                // left to up
                matrix[start][i] = matrix[end - offset][start];
                // bottom to left
                matrix[end - offset][start] = matrix[end][end - offset];
                // right to bottom
                matrix[end][end - offset] = matrix[i][end];
                // up to right
                matrix[i][end] = temp;
            }
        }
    }

    /*
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],


[
  [1,4,7],
  [2,5,8],
  [3,6,9]
],

     */

    public void rotate2(int[][] matrix) {
        if (matrix == null)
            return;
        int n = matrix.length;
        // 沿着副对角线旋转, i, j 调换
        for (int row = 0; row < n; row++)
            for (int col = row; col < n; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        // 沿着中线左右调换
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n / 2; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[row][n - 1 - col];
                matrix[row][n - 1 - col] = temp;
            }
    }
}
