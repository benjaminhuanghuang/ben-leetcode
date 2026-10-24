public class Solution566
{
    public int[,] MatrixReshape(int[,] nums, int r, int c)
    {
        if (nums == null || r == 0 || c == 0)
            return nums;
        int rows = nums.GetLength(0);
        int cols = nums.GetLength(1);
        if (rows == 0 || cols == 0)
            return nums;
        if (rows * cols != r * c)
            return nums;

        int[,] res = new int[r, c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res[i, j] = nums[(i * c + j) / cols, (i * c + j) % cols];
            }
        }
        return res;
    }
}