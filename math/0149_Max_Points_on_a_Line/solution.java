package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4

Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6


 */
public class LC_0149_MaxPointsonaLine {
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
    用斜率作hashmap的key。其中斜率要注意x = 0的情况，即将vertical的数单独计算。
    同时还有一个问题是重复的问题，之前的思路是如果重复，那就给通过该节点向量中的每个向量的计数+1，但是这样带来了一些问题，当新添加向量时，然后确定计数值。
    后来为了简单起见，当出现重复的时候，直接将一个duplicate值更新。然后当处理完所有的节点之后，再对所有的向量值进行一次遍历，然后将value+dulplicate与max比较，并对max更新。
     */
    public int maxPoints(Point[] points) {
        if (points.length == 0 || points == null)
            return 0;

        if (points.length == 1)
            return 1;

        int max = 1;  //the final max value, at least one

        for (int i = 0; i < points.length; i++) {
            HashMap<Double, Integer> map = new HashMap<>();   // slop: points
            int same = 0;
            int localmax = 1; //the max value of current slope, at least one
            for (int j = 0; j < points.length; j++) {
                if (i == j)
                    continue;

                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                    continue;
                }
                //https://leetcode.com/problems/max-points-on-a-line/discuss/111270/a-work-around-for-0094911151949111509491115294911151
                double slope = ((double) (points[i].y - points[j].y)) * 100.0/ (points[i].x - points[j].x);

                if (map.containsKey(slope))
                    map.put(slope, map.get(slope) + 1);
                else
                    map.put(slope, 2);  //two points form a line
            }

            for (Integer value : map.values())
                localmax = Math.max(localmax, value);

            localmax += same;
            max = Math.max(max, localmax);
        }
        return max;
    }
}
