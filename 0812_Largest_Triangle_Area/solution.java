package cn.huang.leetcode;

/*
    812. Largest Triangle Area

    You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

    Example:
    Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]

    Output: 2
    Explanation:
    The five points are show in the figure below. The red triangle is the largest.
 */
public class LC_0812_LargestTriangleArea {
    public double largestTriangleArea(int[][] points) {
        double res = 0;
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i == j) continue;
                for (int k = j + 1; k < points.length; k++) {
                    if (k == i || k == j) continue;
                    double tmp = area(points[i], points[j], points[k]);
                    res = res < tmp ? tmp : res;
                }
            }
        }
        return res;
    }

    public double area(int[] x, int[] y, int[] z) {
        return 0.5 * (x[0] * y[1] + y[0] * z[1] + z[0] * x[1] - x[0] * z[1] - y[0] * x[1] - z[0] * y[1]);
    }
}
