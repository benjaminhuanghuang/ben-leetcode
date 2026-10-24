/*
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * public class Interval {
 *     public int start;
 *     public int end;
 *     public Interval() { start = 0; end = 0; }
 *     public Interval(int s, int e) { start = s; end = e; }
 * }
 */
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution056 {
    public IList<Interval> Merge(IList<Interval> intervals) {
        var res = new List<Interval>();
        intervals = intervals.OrderBy(x => x.start).ToList();

        for (int i = 0; i < intervals.Count; i++)
        {
            var newInterval = new Interval(intervals[i].start, intervals[i].end);
            while (i < intervals.Count - 1 && newInterval.end >= intervals[i + 1].start)
            {
                newInterval.end = Math.Max(newInterval.end, intervals[i + 1].end);
                i++;
            }

            res.Add(newInterval);
        }

        return res;
    }
}