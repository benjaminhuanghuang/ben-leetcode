package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
    447. Number of Boomerangs
    Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k)
    such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

    Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the
    range [-10000, 10000] (inclusive).

    Example:
    Input:
    [[0,0],[1,0],[2,0]]

    Output:
    2

    Explanation:
    The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */
public class LC_0447_NumberofBoomerangs {
    public int numberOfBoomerangs(int[][] points) {
        //HashMap去存储距离和这个距离出现的次数。
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int res = 0;
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i == j) continue;
                List<Integer> list = new ArrayList<Integer>();
                int distance = getDistance(points[i], points[j]);
                if (map.containsKey(distance)) {
                    map.put(distance, map.get(distance) + 1);
                } else {
                    map.put(distance, 1);
                }
            }
            for (int value : map.values()) {
                //要依次选择每个点当做第一个点,排列组合结果数
                res += value * (value - 1);
            }
            map.clear();
        }
        return res;
    }

    public static int getDistance(int[] pointOne, int[] pointTwo) {
        int distance = (int) Math.pow(pointOne[0] - pointTwo[0], 2) + (int) Math.pow(pointOne[1] - pointTwo[1], 2);
        return distance;
    }

}
