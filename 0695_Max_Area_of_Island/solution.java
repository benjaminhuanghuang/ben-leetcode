package cn.huang.leetcode;
/*
695. Max Area of Island
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 */
public class LC_0695_MaxAreaofIsland {
    int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int maxAreaOfIsland(int[][] grid) {
        int result = 0;
        int m = grid.length;
        int n = grid[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result = Math.max(result, dfs(grid, i, j, m, n));
                }
            }
        }
        return result;
    }

    int dfs(int[][] grid, int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
            return 0;
        }
        int count = 1;
        grid[x][y] = 0;  // important!
        for (int[] step : steps) {
            count += dfs(grid, x + step[0], y + step[1], m, n);
        }
        return count;
    }
}
