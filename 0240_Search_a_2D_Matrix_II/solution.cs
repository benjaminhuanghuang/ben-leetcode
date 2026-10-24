public class Solution240 {
    // O(m + n)
    public bool SearchMatrix(int[,] matrix, int target) {
        int col = matrix.GetLength(1);
        for(int row =0; row < matrix.GetLength(0); row++)
        {
            while(col >=0 && matrix[row, col] > target)
            {
                col --;
            }
            if (matrix[row, col] == target)
                return true;
        }
        return false;
    }
    
    // bin search 0(m*LogN)
    public bool SearchMatrix_Bin(int[,] matrix, int target) {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        int row = 0, col = cols - 1;

        while (row < rows && col >-0)
        {
            if (matrix[row, col] == target)
                return true;
            else if(matrix[row, col] < target)
                row ++;
            else
                col --;
        }
        return false;
    }
}