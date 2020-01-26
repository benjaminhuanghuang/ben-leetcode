package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.TreeSet;

/*
352. Data Stream as Disjoint Intervals

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a
list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]

Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

 */

/*
    tree set:
    The floor() method returns the greatest element in this set less than or equal to the given element, or null if
      there is no such element.

    The higher() method returns the least element in this set strictly greater than the given element, or null if there
    is no such element. Note: we use higher() instead of ceiling() to exclude the given element.
 */
public class LC_0352_DataStreamasDisjointIntervals {
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

    class SummaryRanges {
        TreeSet<Interval> set;

        /**
         * Initialize your data structure here.
         */
        public SummaryRanges() {
            set = new TreeSet<Interval>(new Comparator<Interval>() {
                public int compare(Interval a, Interval b) {
                    return a.start - b.start;
                }
            });
        }

        public void addNum(int val) {
            Interval t = new Interval(val, val);

            Interval floor = set.floor(t);
            if (floor != null) {
                if (val <= floor.end) {
                    return;
                } else if (val == floor.end + 1) {
                    t.start = floor.start;
                    set.remove(floor);
                }
            }

            Interval ceil = set.higher(t);
            if (ceil != null) {
                if (ceil.start == val + 1) {
                    t.end = ceil.end;
                    set.remove(ceil);
                }
            }

            set.add(t);
        }

        public List<Interval> getIntervals() {
            return new ArrayList(set);
        }
    }
}
