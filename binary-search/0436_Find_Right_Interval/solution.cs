/*
436. Find Right Interval

Given a set of intervals, for each of the interval i, check if there exists an interval j whose start 
point is bigger than or equal to the end point of the interval i, which can be called that j is on the 
"right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j 
has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't 
exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:
You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
Example 1:
Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
Example 2:
Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
Example 3:
Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
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