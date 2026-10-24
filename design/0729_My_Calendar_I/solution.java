package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.List;

/*
729. My Calendar I
 Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

Example 1:

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation:
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.

Note:
The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
 */
public class LC_0729_MyCalendar_I {
    class MyCalendar {

        List<int[]> bookings;

        public MyCalendar() {
            bookings = new LinkedList<>();
        }

        public boolean book(int start, int end) {
            int s = 0, e = bookings.size() - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                int[] bk = bookings.get(mid);
                if (bk[0] == start) {
                    return false;
                } else if (bk[0] > start) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            if (s > 0 && start < bookings.get(s - 1)[1])
                return false;
            if (s < bookings.size() && end > bookings.get(s)[0])
                return false;
            bookings.add(s, new int[]{start, end});
            return true;
        }

        private boolean isOverlap(int s1, int e1, int s2, int e2) {
            return Math.max(s1, s2) < Math.min(e1, e2);
        }
    }
}
