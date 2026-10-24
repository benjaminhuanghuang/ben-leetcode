package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
54. Spiral Matrix

 */
public class LC_0054_SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix.length == 0)
            return res;

        int rowStart=0;
        int rowEnd=matrix.length-1;

        int colStart=0;
        int colEnd = matrix[0].length-1;


        while(rowStart <= rowEnd && colStart <= colEnd){

            // Left to right
            for (int i = colStart; i <= colEnd; i++) {
                res.add(matrix[rowStart][i]);
            }

            // top to bottom
            for (int j = rowStart+1; j <= rowEnd; j++) {
                res.add(matrix[j][colEnd]);
            }

            // right to left
            if(rowStart+1 <= rowEnd){
                for (int k = colEnd-1; k >= colStart; k--) {
                    res.add(matrix[rowEnd][k]);
                }
            }
            if(colStart+1 <= colEnd){
                for (int k = rowEnd-1; k > rowStart; k--) {
                    res.add(matrix[k][colStart]);
                }
            }

            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }
        return res;
    }
}
