package cn.huang.leetcode;

import cn.huang.leetcode.common.Interval;

import java.util.ArrayList;
import java.util.List;

/*
57. Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


 */
public class LC_0057_InsertInterval {

    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        if (newInterval == null) {
            return intervals;
        }
        // if the input is unsorted, add: (which will make this algo O(nlogn) time)
        // Collections.sort(intervals, new Comparator<Interval>(){
        //     public int compare(Interval a, Interval b) {
        //         return a.start - b.start;
        //     }
        // });
        List<Interval> res = new ArrayList<>();
        int i = 0;
        while (i < intervals.size() && intervals.get(i).end < newInterval.start) {
            res.add(intervals.get(i++));
        }
        //then we try to merge all intervals that can be merged
        while (i < intervals.size() && intervals.get(i).start <= newInterval.end) {//这里的等号特别容易忘
            newInterval.start = Math.min(newInterval.start, intervals.get(i).start);//remember to update the start !!!
            newInterval.end = Math.max(newInterval.end, intervals.get(i++).end);
        }
        res.add(newInterval);//add the newInterval when no overlap exists
        while (i < intervals.size()) {
            res.add(intervals.get(i++));//add the rest of the non overlapping intervals
        }
        return res;
    }
}
