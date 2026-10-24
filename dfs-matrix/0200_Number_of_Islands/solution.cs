public class Solution200 {
    // 一个只包含字符0和1的二维数组，找出里面不相邻的只包含1的块的个数。
    // 碰到一个1，就把它周围所有相连的1都标记为 visited，
    private int count = 0;
    private bool[,] visited;
    
    public int NumIslands(char[,] grid) {
        var rows = grid.GetLength(0);
        var columns = grid.GetLength(1);

        visited = new bool[rows, columns];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i, j] == '1' && !visited[i,j])
                {
                    this.NumIslandsHelper(grid, i, j);
                    count++;
                }
            }
        }

        return count;   
    }

    private void NumIslandsHelper(char[,] grid, int i, int j)
    {
        if (i < 0 || i >= grid.GetLength(0)) return;
        if (j < 0 || j >= grid.GetLength(1)) return;
        if (visited[i, j]) return;
        if (grid[i, j] != '1') return;

        visited[i, j] = true;

        this.NumIslandsHelper(grid, i - 1, j);
        this.NumIslandsHelper(grid, i + 1, j);
        this.NumIslandsHelper(grid, i, j - 1);
        this.NumIslandsHelper(grid, i, j + 1);
    }
}