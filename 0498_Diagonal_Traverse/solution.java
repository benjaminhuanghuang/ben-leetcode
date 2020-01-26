package cn.huang.leetcode;
/*
498. Diagonal Traverse
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown
in the below image.



Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:
 */

/*

 */
public class LC_0498_DiagonalTraverse {
    public int[] findDiagonalOrder(int[][] matrix) {
        int rows = matrix.length;
        if(rows == 0)
            return new int[0];

        int cols = matrix[0].length;
        int[] arr = new int[rows * cols];

        int row = 0;
        int col = 0;
        for (int i = 0; i < arr.length; i++) {
            arr[i] = matrix[row][col];
            if ((row + col) % 2 == 0)  // moving up
            {
                if (col == cols - 1)
                    row++;
                else if (row == 0)
                    col++;
                else {
                    row--;      // move up
                    col++;
                }
            } else //going down
            {
                if (row == rows - 1)
                    col++;
                else if (col == 0)
                    row++;
                else {
                    row++;
                    col--;
                }
            }
        }
        return arr;
    }
}
