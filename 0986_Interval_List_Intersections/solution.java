package cn.huang.leetcode;

import cn.huang.leetcode.common.Interval;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/*
986. Interval List Intersections

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a
closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)



Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]],
       B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.


Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 */
public class LC_0986_IntervalListIntersections {
    public Interval[] intervalIntersection(Interval[] A, Interval[] B) {
        List<Interval> res = new ArrayList<>();

        if (A == null || A.length == 0 || B == null || B.length == 0)
            return new Interval[0];

        Arrays.sort(A, new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.start - o2.start;
            }
        });

        Arrays.sort(B, new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.start - o2.start;
            }
        });
        int ib = 0;
        for (int i = 0; i < A.length; i++) {
            if (B[ib].start > A[i].end) {
                continue;  // move A
            }
            while (B[ib].end < A[i].start && ib < B.length) {
                ib++;
            }
            //
        }
        return res.toArray(new Interval[res.size()]);
    }

    /*
    Hua Hua
    https://zxi.mytechroad.com/blog/2019/02/
    Time complexity: O(m + n)
    Space complexity: O(1)
     */
    public Interval[] intervalIntersection2(Interval[] A, Interval[] B) {
        List<Interval> res = new ArrayList<>();

        int i = 0;
        int j = 0;

        while (i < A.length && j < B.length) {
            int s = Math.max(A[i].start, B[j].start);
            int e = Math.min(A[i].end, B[j].end);
            if (s <= e)
                res.add(new Interval(s, e));
            if (A[i].end < B[j].end)
                ++i;
            else
                ++j;
        }
        return res.toArray(new Interval[res.size()]);
    }
}
