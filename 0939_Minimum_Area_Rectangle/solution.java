package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
939. Minimum Area Rectangle
Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.



Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 */
public class LC_0939_MinimumAreaRectangle {
    /*
    两点（对角线）确定一个长方形，遍历所以可能的点对，最后找到最小的
     */
    public int minAreaRect(int[][] points) {
        if(points == null || points.length == 0)
            return 0;

        int min = Integer.MAX_VALUE;
        Map<Integer, List<Integer>> x2y = new HashMap<>(); //将x相同的点，其y放在一个列表中

        for(int[] point : points) {
            if(!x2y.containsKey(point[0])) {
                List<Integer> list = new ArrayList<>();
                list.add(point[1]);
                x2y.put(point[0], list);
            }else {
                x2y.get(point[0]).add(point[1]);
            }
        }

        int len = points.length;
        for(int i = 1; i < len; i++) {
            for(int j = i - 1; j >=0; j--) {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1]) {
                    continue;
                }
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x2y.get(x1).contains(y2) && x2y.get(x2).contains(y1)) { //如果能找到这样的长方形，计算其面积
                    min = Math.min(min, Math.abs(x1 - x2) * Math.abs(y1- y2));
                }
            }
        }
        if(min == Integer.MAX_VALUE) {
            return 0;
        }
        return min;
    }
}
