package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/*
253. Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
 */
public class LC_0253_MeetingRooms_II {
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
    对起始时间进行排序，使用最小堆来记录当前会议的结束时间，当心会议的起始时间大于最小堆中的最早结束时间，说明新会议与堆中的最早结束会议不重叠。
     */
    public int minMeetingRooms(Interval[] intervals) {
        Arrays.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return Integer.compare(i1.start, i2.start);
            }
        });
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int rooms = 0;
        /*
        Then a new event comes, we greedily choose the event X that finished the earliest, if the new event does not overlap
        with the X, the new event can reuse the room
         */
        for (int i = 0; i < intervals.length; i++) {
            minHeap.offer(intervals[i].end);
            if (intervals[i].start < minHeap.peek()) {
                rooms++;
            } else {
                minHeap.poll();  // note!
            }
        }
        return rooms;
    }
}
