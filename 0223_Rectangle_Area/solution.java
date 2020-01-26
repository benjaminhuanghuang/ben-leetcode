package cn.huang.leetcode;

/*

223. Rectangle Area

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
 */
public class LC_0223_RectangleArea {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G)
            return sum;
        return sum - ((Math.min(G, C) - Math.max(A, E)) * (Math.min(D, H) - Math.max(B, F)));
    }

    public int computeArea2(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);

        int overlapRegion = overlap(A, B, C, D, E, F, G, H);
        return area1 + area2 - overlapRegion;
    }

    private int overlap(int A, int B, int C, int D, int E, int F, int G, int H) {
        int h1 = Math.max(A, E);
        int h2 = Math.min(C, G);
        int h = h2 - h1;

        int v1 = Math.max(B, F);
        int v2 = Math.min(D, H);
        int v = v2 - v1;

        if (h <= 0 || v <= 0) return 0;
        else return h * v;
    }
}
