package cn.huang.leetcode;

import java.util.Arrays;

/*
	883	 Projection Area of 3D Shapes

    On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.

    Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

    Now we view the projection of these cubes onto the xy, yz, and zx planes.

    A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane.

    Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

    Return the total area of all three projections.



    Example 1:

    Input: [[2]]
    Output: 5
    Example 2:

    Input: [[1,2],[3,4]]
    Output: 17
    Explanation:
 */
public class LC_0883_ProjectionAreaof3DShapes {
    public int projectionArea(int[][] grid) {
        int top = 0;

        int[] maxInRow = new int[grid.length];
        int[] maxInCol = new int[grid.length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (grid[i][j] > 0)
                    top++;

                maxInRow[i] = Math.max(grid[i][j], maxInRow[i]);
                maxInCol[j] = Math.max(grid[i][j], maxInCol[j]);
            }
        }
//        return top +  Arrays.stream(maxInRow).sum() +  Arrays.stream(maxInCol).sum();    // very slow!!!
        return top + sumArray(maxInRow) + sumArray(maxInCol);
    }

    private int sumArray(int[] array) {
        int sum = 0;
        for (int v : array) {
            sum += v;
        }
        return sum;
    }

}
