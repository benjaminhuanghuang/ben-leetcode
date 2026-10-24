package cn.huang.leetcode;

import cn.huang.leetcode.common.Interval;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/*
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


 */
public class LC_0056_MergeIntervals {

    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new ArrayList<>();
        if (intervals == null || intervals.size() == 0)
            return res;

        intervals.sort(new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.start - o2.start;
            }
        });

        for (int i = 0; i < intervals.size(); i++) {
            Interval newInterval = new Interval(intervals.get(i).start, intervals.get(i).end);
            while (i < intervals.size() - 1 && newInterval.end >= intervals.get(i + 1).start) {
                newInterval.end = Math.max(newInterval.end, intervals.get(i + 1).end);
                i++;
            }

            res.add(newInterval);
        }
        return res;
    }
}
