package cn.huang.leetcode;

/*

    On a N * N grid, we place some 1 * 1 * 1 cubes.

    Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

    Return the total surface area of the resulting shapes.



    Example 1:

    Input: [[2]]
    Output: 10
    Example 2:

    Input: [[1,2],[3,4]]
    Output: 34
    Example 3:

    Input: [[1,0],[0,2]]
    Output: 16
    Example 4:

    Input: [[1,1,1],[1,0,1],[1,1,1]]
    Output: 32
    Example 5:

    Input: [[2,2,2],[2,1,2],[2,2,2]]
    Output: 46


    Note:

    1 <= N <= 50
    0 <= grid[i][j] <= 50
 */
public class LC_0892_SurfaceAreaof3DShapes {
    public int surfaceArea(int[][] grid) {
        int answer = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (grid[i][j] > 0)
                    answer += grid[i][j] * 4 + 2; // Top of stack + bottom of stack + reminaing 4 at each level
                if (i != 0)
                    answer -= Math.min(grid[i][j], grid[i - 1][j]) * 2; //find the cubes common to this cube from top
                if (j != 0)
                    answer -= Math.min(grid[i][j], grid[i][j - 1]) * 2; // find the cubes common to this cube from left
            }
        }
        return answer;
    }
}
