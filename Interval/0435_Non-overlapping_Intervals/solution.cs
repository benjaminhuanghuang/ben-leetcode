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

public class Solution435 {
    public int EraseOverlapIntervals(Interval[] intervals) {
        // sort by start then end
        // Array.Sort(intervals, (x,y) =>{ int result = x.end.CompareTo(y.end); 
        //                                      return result == 0 ? x.start.CompareTo(x.start) : result; });
        Array.Sort(intervals, (x,y) =>{return x.end.CompareTo(y.end);});  

        int end = Int32.MinValue;
        //ans为可以两两互不相交的最大区间数
        int ans = 0;
        // 遍历排序后的区间，若当前区间的起点≥end，则更新end为当前区间的终点，并将计数器ans+1
        foreach( Interval i in intervals)
        {
            if (i.start >= end)
            {
                end = i.end;
                ans ++;
            }
        }

        return intervals.Length - ans;
    }
}