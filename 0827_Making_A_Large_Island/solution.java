package cn.huang.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
827. Making A Large Island [200]

In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.



Notes:

    1 <= grid.length = grid[0].length <= 50.
    0 <= grid[i][j] <= 1.

 */
public class LC_0827_MakingALargeIsland
{
    /*
    https://www.youtube.com/watch?v=KqkXZpRB1x8
     */
    public int largestIsland(int[][] grid) {
        if (grid == null || grid.length == 0)
            return 0;

        int n = grid.length;
        int startFlag = 2;

        Map<Integer, Integer> sizeMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    boolean[][] visited = new boolean[n][n];
                    int size = dfs(grid, i, j, visited, startFlag);
                    sizeMap.put(startFlag, size);
                    startFlag++;
                }
            }
        }

        int max = 0;
        boolean hasZero = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    Set<Integer> set = new HashSet<>();
                    if (i - 1 >= 0) {
                        set.add(grid[i - 1][j]);
                    }
                    if (i + 1 < n) {
                        set.add(grid[i + 1][j]);
                    }
                    if (j - 1 >= 0) {
                        set.add(grid[i][j - 1]);
                    }
                    if (j + 1 < n) {
                        set.add(grid[i][j + 1]);
                    }

                    int size = 1;
                    for (int inner : set) {
                        if (sizeMap.containsKey(inner)) {
                            size += sizeMap.get(inner);
                        }
                    }
                    max = Math.max(max, size);
                }
            }
        }

        return !hasZero ? n * n : max;
    }

    public int dfs(int[][] grid, int x, int y, boolean[][] visited, int flag) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || visited[x][y] || grid[x][y] != 1)
            return 0;
        grid[x][y] = flag;
        visited[x][y] = true;
        return 1 + dfs(grid, x - 1, y, visited, flag)
                + dfs(grid, x + 1, y, visited, flag)
                + dfs(grid, x, y - 1, visited, flag)
                + dfs(grid, x, y + 1, visited, flag);
    }
}
