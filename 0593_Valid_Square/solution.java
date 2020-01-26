package cn.huang.leetcode;

import java.util.HashSet;
import java.util.Set;

/*
593. Valid Square

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True

Note:

    All the input integers are in the range [-10000, 10000].
    A valid square has four equal sides with positive length and four equal angles (90-degree angles).
    Input points have no order.

 */
public class LC_0593_ValidSquare {
    /*
    正方形的四条边相等，两条对角线相等，满足这两个条件的四边形一定是正方形。
    只需要对四个点，两两之间算距离，如果计算出某两个点之间距离为0，说明两点重合了，
     */
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        Set<Integer> s = new HashSet<>();
        s.add(distSqr(p1, p2));
        s.add(distSqr(p1, p3));
        s.add(distSqr(p1, p4));
        s.add(distSqr(p2, p3));
        s.add(distSqr(p2, p4));
        s.add(distSqr(p3, p4));


        return !s.contains(0) && s.size() == 2;
    }

    private int distSqr(int[] p1, int[] p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
}
