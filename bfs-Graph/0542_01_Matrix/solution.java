package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.Queue;

/*
542. 01 Matrix

 Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input:

0 0 0
0 1 0
0 0 0

Output:

0 0 0
0 1 0
0 0 0

Example 2:
Input:

0 0 0
0 1 0
1 1 1

Output:

0 0 0
0 1 0
1 2 1

Note:

    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.

 */
public class LC_0542_01_Matrix {
    /*
    https://www.jiuzhang.com/solution/01-matrix/
     */
    public int[][] updateMatrix(int[][] matrix) {
        // write your code here
        Queue <int[]> bfs = new LinkedList<>();
        final int rows = matrix[0].length;
        final int cols = matrix.length;
        int [][] res = new int[cols][rows];

        for(int i=0; i<cols;++i){
            for(int j=0; j<rows;++j){
                if(matrix[i][j]==0){
                    bfs.add(new int[]{i,j,0});
                    res[i][j]=0;
                }
                else{
                    res[i][j]=Integer.MAX_VALUE;
                }
            }
        }
        int [][] direct = new int[][]{{0,1},{1,0},{-1,0},{0,-1}};
        while(!bfs.isEmpty()){
            int [] pos = bfs.remove();
            int nextVal =  pos[2]+1;
            for(int[] dir:direct){
                int nextRow = pos[0]+dir[0];
                int nextCol = pos[1]+dir[1];
                if(nextRow>=0 && nextCol>=0 && nextRow<cols && nextCol<rows && res[nextRow][nextCol]==Integer.MAX_VALUE){
                    res[nextRow][nextCol]=nextVal;
                    bfs.add(new int[]{nextRow,nextCol,nextVal});
                }

            }
        }
        return res;
    }
}
