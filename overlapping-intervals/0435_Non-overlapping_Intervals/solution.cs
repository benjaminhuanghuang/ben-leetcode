/*
435. Non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you need to remove to make the 
rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
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