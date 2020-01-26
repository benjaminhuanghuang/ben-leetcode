package cn.huang.leetcode;
/*
778. Swim in Rising Water

On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

Note:

    2 <= N <= 50.
    grid[i][j] is a permutation of [0, ..., N*N - 1].


 */

/*
一道二分查找和DFS相结合的题目，个人觉得是一道不错的面试题。通过抽茧剥丝，我们发现这道题目其实就是求从grid的左上角到右下角的所有路径中，最大值最小的路径中的最大值（原谅我说的有点绕^_^）。

我们可以对该值进行二分查找：该值的最小可能取值就是grid中的最小值，最大可能取值就是grid中的最大值。我们分别定义它们为left和right。然后就二分查找left和right中的合适值，使得从grid的左上角到右下角有路径可达且阈值最小。在针对mid做一次DFS之后，可能会出现两种情况：

1）以mid为阈值无法从左上角到右下角，所以此时我们需要提高阈值，即让left = mid + 1；

2）以mid为阈值可以从左上角到右下角，所以此时我们可以降低阈值，即让right = mid - 1，以便于找到更小的阈值。

 */
public class LC_0778_SwiminRisingWater
{
    private int[][] grid;
    private int n;
    private static final int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int swimInWater(int[][] grid) {
        this.grid = grid;
        n = grid.length;

        int maxInPath = grid[0][0];
        boolean[][] visited = new boolean[n][n];

        while (!visited[n - 1][n - 1]) {
            visited = new boolean[n][n];
            dfs(0, 0, visited, maxInPath);
            maxInPath++;
        }

        return maxInPath - 1;
    }

    private void dfs(int x, int y, boolean[][] visited, int maxInPath) {
        for (int[] direction: directions) {
            int nx = x + direction[0];
            int ny = y + direction[1];
            if (nx >= n || nx < 0 || ny >= n || ny < 0 || visited[nx][ny] || grid[nx][ny] > maxInPath)
                continue;
            visited[nx][ny] = true;
            dfs(nx, ny, visited, maxInPath);
        }
    }
}
