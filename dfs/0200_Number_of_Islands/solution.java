package cn.huang.leetcode;

/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), moves the number of islands. An island is surrounded
by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four
edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3

 */
public class LC_0200_NumberofIslands {
    // 一个只包含字符0和1的二维数组，找出里面不相邻的只包含1的块的个数。
    // 碰到一个1，就把它周围所有相连的1都标记为 visited，
    private int count = 0;
    private boolean[][] visited;

    public int numIslands(char[][] grid) {
        if(grid == null || grid.length ==0)
            return 0;

        int rows = grid.length;
        int cols = grid[0].length;

        visited = new boolean[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    this.helper(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    private void helper(char[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length) return;
        if (j < 0 || j >= grid[0].length) return;
        if (visited[i][j]) return;
        if (grid[i][j] != '1') return;

        visited[i][j] = true;

        this.helper(grid, i - 1, j);
        this.helper(grid, i + 1, j);
        this.helper(grid, i, j - 1);
        this.helper(grid, i, j + 1);
    }
}

