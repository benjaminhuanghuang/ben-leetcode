package cn.huang.leetcode;
/*
 867 Transpose Matrix
 Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal,
switching the row and column indices of the matrix.

 */
public class LC_0867_TransposeMatrix {
    public int[][] transpose(int[][] A) {
        int rows = A.length;
        int cols = A[0].length;

        int[][] A_T = new int[cols][rows];
        for (int r =0 ; r < rows; r++ )
        {
            for (int c =0 ; c < cols; c++ )
            {
                A_T[c][r] = A[r][c];
            }
        }

        return A_T;
    }
}
