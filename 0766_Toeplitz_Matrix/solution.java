package cn.huang.leetcode;

/*
    766. Toeplitz Matrix
 */
public class LC_0766_ToeplitzMatrix {
    public boolean isToeplitzMatrix(int[][] matrix) {
        if (matrix == null)
            return false;

        for (int i = 1; i < matrix.length; ++i)
            for (int j = 1; j < matrix[0].length; ++j)
                if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
        return true;
    }
}
/*
[[36,59,71,15,26,82,87],
 [56,36,59,71,15,26,82],
 [15,0,36,59,71,15,26]]
 */