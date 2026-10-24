package cn.huang.leetcode;
/*
994. Rotting Oranges

In a given grid, each cell can have one of three values:

    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.



Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.



Note:

    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] is only 0, 1, or 2.
 */

import basic.QueueDemo;

import java.util.LinkedList;
import java.util.Queue;

/*
    BFS 每次扩展1格
    Time complexity: O(mn)
    Space complexity: O(mn)
 */
public class LC_0994_RottingOranges
{
    public int orangesRotting(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        Queue<int[]> q = new LinkedList<>();

        int fresh = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1)
                    ++fresh;
                else if (grid[i][j] == 2)
                    q.offer(new int[]{j, i});
            }
        }

        int[] dirs = new int[] {1, 0, -1, 0, 1};
        int days = 0;
        while (!q.isEmpty() && fresh>0) {
            int size = q.size();
            while (size>0) {
                int[] pair = q.poll();
                int x = pair[0];
                int y = pair[1];

                for (int i = 0; i < 4; ++i) {
                    int dx = x + dirs[i];
                    int dy = y + dirs[i + 1];
                    if (dx < 0 || dx >= cols || dy < 0 || dy >= rows || grid[dy][dx] != 1)
                        continue;
                    --fresh;
                    grid[dy][dx] = 2;
                    q.offer(new int[]{dx, dy});
                }
                size--;
            }
            ++days;
        }
        return fresh > 0 ? -1 : days;
    }
}
