package cn.huang.leetcode;

import java.util.Arrays;

/*
    436. Find Right Interval

     Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is
     bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum
start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval
i. Finally, you need output the stored value of each interval as an array.

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
public class LC_0436_FindRightInterval {
    public class Interval {
        int start;
        int end;

        Interval() {
            start = 0;
            end = 0;
        }

        Interval(int s, int e) {
            start = s;
            end = e;
        }
    }

    public int[] findRightInterval(Interval[] intervals) {
        Interval[] sortedIntervals = Arrays.copyOf(intervals, intervals.length);
        Arrays.sort(sortedIntervals, (o1, o2) -> o1.start - o2.start);

        int[] result = new int[intervals.length];
        for (int i = 0; i < intervals.length; i++) {
            Interval current = intervals[i];
            int insertIndex = Arrays.binarySearch(sortedIntervals, current, (o1, o2) -> o1.start - o2.end);
            if (insertIndex < 0) {
                insertIndex = -insertIndex - 1;
            }
            if (insertIndex == intervals.length) {
                result[i] = -1;
            } else {
                Interval match = sortedIntervals[insertIndex];
                for (int j = 0; j < intervals.length; j++) {
                    if (i != j && match.start == intervals[j].start && match.end == intervals[j].end) {
                        // System.out.println(",old index:"+j);
                        result[i] = j;
                    }
                }
            }

        }
        return result;
    }
}
