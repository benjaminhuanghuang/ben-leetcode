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
