package cn.huang.leetcode;
/*
963. Minimum Area Rectangle II

Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points,
with sides not necessarily parallel to the x and y axes.

If there isn't any rectangle, return 0.

Example 1:



Input: [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
Example 2:



Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
Example 3:



Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.
Example 4:



Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.


Note:

1 <= points.length <= 50
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
Answers within 10^-5 of the actual value will be accepted as correct.

 */

/*
    给定一组坐标，找出四个顶点使其能构成长方形，求最小的长方形的面积。注意，边有可能不和x,y轴平行。
 */

import java.util.HashSet;
import java.util.Set;

public class LC_0963_MinimumAreaRectangle_II {
    /*
     先找到前三个点，再找到第四个点，然后计算面积
     */
    public double minAreaFreeRect(int[][] points) {
        Set<String> set = new HashSet<>();
        double result = Double.MAX_VALUE;
        // 构造点集
        for(int[] p : points){
            set.add(p[0] + " " + p[1]);
        }
        //通过第三个点求第四个点
        for(int[] p1 : points){
            for(int[] p2 : points){
                if(p1[0] == p2[0] && p1[1] == p2[1]){
                    continue;
                }
                for(int[] p3 : points){
                    //勾股定理
                    if(dist(p1, p3) + dist(p2, p3) != dist(p1, p2)){
                        continue;
                    }
                    //第四个点的坐标
                    int x = p1[0] + p2[0] - p3[0];
                    int y = p1[1] + p2[1] - p3[1];
                    //第四个点是否在点集中存在
                    if(!set.contains(x + " " + y)){
                        continue;
                    }
                    double area = Math.sqrt(dist(p1, p3)) * Math.sqrt(dist(p2, p3));
                    if(area == 0){
                        continue;
                    }
                    result = Math.min(result, area);
                }
            }
        }
        return result == Double.MAX_VALUE ? 0 : result;
    }
    public double dist(int[] x1, int[] x2){
        return (x1[0] - x2[0]) * (x1[0] - x2[0]) + (x1[1] - x2[1]) * (x1[1] - x2[1]);
    }
}
