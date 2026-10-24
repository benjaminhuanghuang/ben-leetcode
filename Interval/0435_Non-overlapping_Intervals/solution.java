package cn.huang.leetcode;

/*
435. Non-overlapping Intervals

 Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

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

import java.util.Arrays;
import java.util.Comparator;

public class LC_0435_NonoverlappingIntervals {
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

    /*
        首先给区间排序，根据每个区间的start来做升序排序，
        然后我们开始要查找重叠区间，判断方法是看如果前一个区间的end大于后一个区间的start，那么一定是重复区间，此时我们结果res自增1，我们需要删除一个，
        那么此时我们究竟该删哪一个呢，为了保证我们总体去掉的区间数最小，我们去掉那个end值较大的区间，而在代码中，我们并没有真正的删掉某一个区间，
        而是用一个变量last指向上一个需要比较的区间，我们将last指向end值较小的那个区间；如果两个区间没有重叠，那么此时last指向当前区间，
     */
    public int eraseOverlapIntervals(Interval[] intervals) {
        int res = 0, n = intervals.length, last = 0;

        Arrays.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.start - o2.start;
            }
        });

        for (int i = 1; i < n; ++i) {
            if (intervals[i].start < intervals[last].end) {
                ++res;
                if (intervals[i].end < intervals[last].end)
                    last = i;
            } else {
                last = i;
            }
        }
        return res;
    }

    /*
    解题思路：

    将数组按照区间尾值大小进行排序，然后找出最多能组成区间不重叠数组的数量，用总的区间个数减去最多区间不重叠数组的数量即为所求的区间重叠数组数量。具体思路及代码如下：
     */
    public int eraseOverlapIntervals2(Interval[] intervals) {
        //判空
        if (intervals == null || intervals.length == 0) {
            return 0;
        }

        //将区间按照区间末尾的值进行升序排序
        Arrays.sort(intervals, Comparator.comparingInt(o -> o.end));
        int end = intervals[0].end;
        int count = 1; //第一个区间计入不重复区间
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i].start < end) {
                continue;
            }
            end = intervals[i].end;
            count++;
        }
        //区间的总个数减去不重复区间的个数即为所求个数
        return intervals.length - count;
    }
}
