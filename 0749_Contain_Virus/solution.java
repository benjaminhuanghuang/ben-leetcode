package cn.huang.leetcode;

/*
749. Contain Virus

 A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated
with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the
shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are
limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected
cells) that threatens the most uninfected cells the following night. There will never be a tie.

Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return
the number of walls used.

Example 1:

Input: grid =
[[0,1,0,0,0,0,0,1],
 [0,1,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,0]]
Output: 10
Explanation:
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

[[0,1,0,0,0,0,1,1],
 [0,1,0,0,0,0,1,1],
 [0,0,0,0,0,0,1,1],
 [0,0,0,0,0,0,0,1]]

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.

Example 2:

Input: grid =
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.

Example 3:

Input: grid =
[[1,1,1,0,0,0,0,0,0],
 [1,0,1,0,1,1,1,1,1],
 [1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.

Note:

    The number of rows and columns of grid will each be in the range [1, 50].
    Each grid[i][j] will be either 0 or 1.
    Throughout the described process, there is always a contiguous viral region that will infect strictly more
    uncontaminated squares in the next round.

 */
public class LC_0749_ContainVirus {
    int[] dx = {0, 0, 1, -1};
    int[] dy = {1, -1, 0, 0};
    int rows, cols;
    int currentColor = 0, bar = 0, uninfected = 0;

    class Cell {
        boolean containVirus;
        boolean blocked;
        int dfsColor;
        int uninfectedColor;

        public Cell(boolean containVirus) {
            this.containVirus = containVirus;
        }
    }

    private void dfs(Cell[][] g, int i, int j) {
        g[i][j].dfsColor = currentColor;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < rows && y >= 0 && y < cols && !g[x][y].blocked) {
                if (g[x][y].containVirus) {
                    if (g[x][y].dfsColor != currentColor)
                        dfs(g, x, y);
                } else {
                    bar++;
                    if (g[x][y].uninfectedColor != currentColor) {
                        uninfected++;
                        g[x][y].uninfectedColor = currentColor;
                    }
                }
            }
        }
    }

    private int doit(Cell[][] g) {
        int colorThreshold = currentColor, maxUninfected = 0, colorUnderMaxUninfected = 0;
        int ans = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (g[i][j].containVirus && !g[i][j].blocked && g[i][j].dfsColor <= colorThreshold) {
                    bar = uninfected = 0;
                    currentColor++;
                    dfs(g, i, j);

                    if (uninfected > maxUninfected) {
                        maxUninfected = uninfected;
                        ans = bar;
                        colorUnderMaxUninfected = currentColor;
                    }
                }
        if (maxUninfected > 0) {
            // First, block the max region
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    if (g[i][j].dfsColor == colorUnderMaxUninfected)
                        g[i][j].blocked = true;

            // Second, expand the remaining viruses.
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    if (!g[i][j].blocked && g[i][j].dfsColor > colorThreshold) {
                        assert (g[i][j].containVirus);
                        for (int k = 0; k < 4; k++) {
                            int x = i + dx[k], y = j + dy[k];
                            if (x >= 0 && x < rows && y >= 0 && y < cols && !g[x][y].blocked)
                                g[x][y].containVirus = true;
                        }
                    }
            ans += doit(g);
        }
        return ans;
    }

    public int containVirus(int[][] grid) {
        rows = grid.length;
        cols = grid[0].length;
        Cell[][] g = new Cell[rows][cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                g[i][j] = new Cell(grid[i][j] == 1);
        return doit(g);
    }
}
