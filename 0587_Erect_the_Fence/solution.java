package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*

587. Erect the Fence

There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is
to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if
all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.



Example 1:

Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:

Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them.



Note:

    All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
    All input integers will range from 0 to 100.
    The garden has at least one tree.
    All coordinates are distinct.
    Input points have NO order. No order required for output.



 */

/*
二维平面的花园里上有一些树，坐标(x, y)。用最短的绳子将这些树围起来。求围出图形边上的所有树的坐标。

注意：

    所有树应该围在一起。不能围成多个组。
    输入整数范围0到100。
    花园至少有一棵树。
    所有坐标不重复。
    输入点坐标无序。输出也不需要有序
 */
public class LC_0587_ErecttheFence {
    class Point {
        int x;
        int y;

        Point() {
            x = 0;
            y = 0;
        }

        Point(int a, int b) {
            x = a;
            y = b;
        }
    }

    /*
        http://massivealgorithms.blogspot.com/2017/05/leetcode-587-erect-fence.html
     */
    public List<Point> outerTrees(Point[] points) {
        Point first = points[0];
        int firstIndex = 0;
        // Find the leftmost point
        for (int i = 0; i < points.length; i++) {
            Point point = points[i];
            if (point.x < first.x) {
                first = point;
                firstIndex = i;
            }
        }

        Set<Point> answer = new HashSet<>();
        Point cur = first;
        int curIndex = firstIndex;
        answer.add(first);

        do {
            Point next = points[0];
            int nextIndex = 0;
            for (int i = 1; i < points.length; i++) {
                if (i == curIndex)
                    continue;
                Point p = points[i];
                int cross = crossProductLength(p, cur, next);
                if (nextIndex == curIndex || cross > 0 ||
                        // Handle multi points in a line
                        (cross == 0 && distance(p, cur) > distance(next, cur))) {
                    next = p;
                    nextIndex = i;
                }
            }
            // Handle multi points in a line
            for (int i = 0; i < points.length; i++) {
                Point p = points[i];
                int cross = crossProductLength(p, cur, next);
                if (i != curIndex && cross == 0) {
                    answer.add(p);
                }
            }

            cur = next;
            curIndex = nextIndex;
        } while (curIndex != firstIndex);

        return new ArrayList<>(answer);
    }

    private int crossProductLength(Point A, Point B, Point C) {
        // Get the vectors' coordinates.
        int BAx = A.x - B.x;
        int BAy = A.y - B.y;
        int BCx = C.x - B.x;
        int BCy = C.y - B.y;

        // Calculate the Z coordinate of the cross product.
        return (BAx * BCy - BAy * BCx);
    }

    private int distance(Point p1, Point p2) {
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }
}
