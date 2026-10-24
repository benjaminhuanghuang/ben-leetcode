public class Solution074 {
    public bool SearchMatrix(int[,] matrix, int target) {
        var cols = matrix.GetLength(1);

        var low = 0;
        var high = matrix.Length - 1;     // matrix.Length = col * row

        while (low <= high)             
        {                 
            var mid = (high - low)/2 + low;     
            // Key point:            
            var col = mid % cols;                 
            var row = mid / cols;                 
            if (matrix[row, col] == target)
            {                     
                return true;                 
            }                 
            else if (matrix[row, col] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
}