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
using System.Collections.Generic;

public class Solution436 {
    //https://discuss.leetcode.com/topic/65708/o-nlogn-naive-python-solution-easy-to-understand
    public int[] FindRightInterval(Interval[] intervals) {
        var original = new Dictionary<int, int>();
        for(int i =0; i < intervals.Length; i++)
        {
            original.Add(intervals[i].start, i);
        }


        int[] res = new int[intervals.Length];
        Array.Sort(intervals, (a, b) => a.start.CompareTo(b.start));

        for(int i =0; i < intervals.Length; i++)
        {
            int left = 0;
            int right = intervals.Length -1;
            while (left < right)
            {
                int mid = left + (right - left)/2;
                if (intervals[mid].start >= intervals[i].end)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (intervals[left].start >= intervals[i].end && left != i)
                res[original[intervals[i].start]] = original[intervals[left].start];
            else
                res[original[intervals[i].start]] = -1;
        }

        return res;
    }
}