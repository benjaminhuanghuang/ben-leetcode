/*
304. Range Sum Query 2D - Immutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper 
left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and 
(row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.


    sums[i][j] = matrix[i-1][j-1] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
    result = sums[r2][c2] + sums[r1][c1] - sums[r2][c1] - sums[r1][c2];
*/
// http://blog.csdn.net/liyuefeilong/article/details/50761072
public class NumMatrix {
    int [,] sumRecord;
    //define an array sum[][] which stores the sum value from (0,0) to the cell[i,j].
    public NumMatrix(int[,] matrix) {
        if(matrix==null || matrix.GetLength(0)==0||matrix.GetLength(1)==0)
            return;
 
        int m = matrix.GetLength(0);
        int n = matrix.GetLength(1);
        sumRecord = new int[m + 1,n + 1];
 
        // 由于sumRegion函数可能被调用多次，因此使用辅助数组sumRecord用于
        // 记录matrix中坐标(0,0)到任一下标(i,j)之间矩形框内元素的值，这样
        // 每次调用sumRegion函数时只需查询sumRecord里的值并进行简单运算即可
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                sumRecord[i,j] = matrix[i - 1,j - 1] + sumRecord[i - 1,j] + 
                                  sumRecord[i,j - 1] - sumRecord[i - 1,j - 1];
    
    }

    public int SumRegion(int row1, int col1, int row2, int col2) {
        if(this.sumRecord==null) 
            return 0;
 
        return sumRecord[row2 + 1,col2 + 1] - sumRecord[row1,col2 + 1] - 
               sumRecord[row2 + 1,col1] + sumRecord[row1,col1];
    }
}
