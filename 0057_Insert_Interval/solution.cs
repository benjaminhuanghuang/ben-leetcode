/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].


*/
using System; 
using System.Linq;
using System.Collections.Generic; 

public class Solution057 {
    public IList<Interval> Insert(IList<Interval> intervals, Interval newInterval) {
        var res = new List<Interval>();
        intervals = intervals.OrderBy(x => x.start).ToList();

        var hasadded = false;

        for (int i = 0; i < intervals.Count; i++)             
        {                 
            if (hasadded)                 
            {                     
                res.Add(intervals[i]);                 
            }                 
            else if (intervals[i].start > newInterval.end)
            {
                res.Add(newInterval);
                res.Add(intervals[i]);
                hasadded = true;
            }
            else if (intervals[i].end < newInterval.start)
            {
                res.Add(intervals[i]);
            }
            else
            {
                newInterval.start = Math.Min(intervals[i].start, newInterval.start);
                newInterval.end = Math.Max(intervals[i].end, newInterval.end);
            }
        }

        if (!hasadded)
        {
            res.Add(newInterval);
        }
        return res;
    }
}