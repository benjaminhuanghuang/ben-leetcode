package cn.huang.leetcode;

import java.util.Comparator;
import java.util.PriorityQueue;

/*
407. Trapping Rain Water II

Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map,
compute the volume of water it is able to trap after raining.



Note:

Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.



Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.



After the rain, water is trapped between the blocks. The total volume of water trapped is 4.

 */
public class LC_0407_TrappingRainWater_II {
    class Cell {
        int x;
        int y;
        int h;

        public Cell(int x, int y, int height) {
            this.x = x;
            this.y = y;
            this.h = height;
        }
    }

    /*
     https://github.com/awangdev/LintCode/blob/master/Java/Trapping%20Rain%20Water%20II.java
     */
    public int trapRainWater(int[][] heights) {
        if (heights == null || heights.length == 0 || heights[0].length == 0) {
            return 0;
        }

        PriorityQueue<Cell> queue = new PriorityQueue<Cell>(1, new Comparator<Cell>() {
            public int compare(Cell A, Cell B) {
                return A.h - B.h;
            }
        });
        int n = heights.length;
        int m = heights[0].length;
        boolean[][] visited = new boolean[n][m];

        //LEFT-RIGHT
        for (int i = 0; i < n; i++) {
            visited[i][0] = true;
            visited[i][m - 1] = true;
            queue.offer(new Cell(i, 0, heights[i][0]));
            queue.offer(new Cell(i, m - 1, heights[i][m - 1]));
        }
        //TOP-BOTTOM
        for (int i = 0; i < m; i++) {
            visited[0][i] = true;
            visited[n - 1][i] = true;
            queue.offer(new Cell(0, i, heights[0][i]));
            queue.offer(new Cell(n - 1, i, heights[n - 1][i]));
        }

        int[] xs = {0, 0, 1, -1};
        int[] ys = {1, -1, 0, 0};
        int sum = 0;
        while (!queue.isEmpty()) {
            Cell cell = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cell.x + xs[i];
                int ny = cell.y + ys[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    sum += Math.max(0, cell.h - heights[nx][ny]);
                    queue.offer(new Cell(nx, ny, Math.max(heights[nx][ny], cell.h)));
                }
            }
        }//end while
        return sum;
    }
}
