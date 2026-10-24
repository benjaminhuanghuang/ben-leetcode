package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
So the median is the mean of the two middle value.
For example,

[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

    void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.



Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2



Follow up:

    If all integer numbers from the stream are between 0 and 100, how would you optimize it?
    If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?


 */
public class LC_0295_FindMedianfromDataStream {
    class MedianFinder {
        private List<Double> values;

        /**
         * initialize your data structure here.
         */
        public MedianFinder() {
            values = new ArrayList<>();
        }

        public void addNum(int num) {
            double val = (double) num;
            if (values.size() == 0) {
                values.add(val);
                return;
            }

            if (num < values.get(0)) {
                values.add(0, val);
                return;
            }

            if (num >= values.get(values.size() - 1)) {
                values.add(val);
                return;
            }
            int l = 0;
            int r = values.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (values.get(m) > num)
                    r = m - 1;
                else
                    l = m + 1;
            }
            values.add(l, val);
        }

        public double findMedian() {
            if (values.size() == 0)
                return 0;
            int mid = values.size() / 2;
            if (values.size() % 2 == 0) {
                return (values.get(mid - 1) + values.get(mid)) / 2;
            } else
                return values.get(mid);
        }
    }

}
