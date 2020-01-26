/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded 
by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four 
edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

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