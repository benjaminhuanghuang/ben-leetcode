package cn.huang.leetcode;

import java.util.TreeSet;

/*

715. Range Module  [56, 57]

A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces
in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval.
Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the
interval [left, right) that are not already tracked.

queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.

removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).

Example 1:

addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)

Note:
A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.
 */

/*
设计数据结构RangeModule，维护一组区间，支持如下操作：

    addRange(int left, int right) 添加区间[left, right)
    queryRange(int left, int right)  判断[left, right)是否完全落在RangeModule涵盖的区间内
    removeRange(int left, int right) 移除[left, right)

 */
public class LC_0715_RangeModule
{
    class RangeModule {

        final int MAX_VALUE = 100000001;
        class Range implements Comparable<Range>{
            int left, right;
            public Range(int left, int right) {
                this.left = left;
                this.right = right;
            }
            public int compareTo(Range another) {
                if (left == another.left) {
                    return right - another.right;
                }
                return left - another.left;
            }
            public String toString() {
                return "Range(" + left + "," + right + ")";
            }
        }
        private TreeSet<Range> ts;
        public RangeModule() {
            ts = new TreeSet<>();
        }

        public void addRange(int left, int right) {
            int nleft = left, nright = right;
            Range high = new Range(right, MAX_VALUE);
            while (true) {
                Range r = ts.lower(high);
                if (r == null || r.right < left) break;
                if (r.right > right) {
                    nright = r.right;
                }
                if (r.left < left) {
                    nleft = r.left;
                }
                ts.remove(r);
            }
            ts.add(new Range(nleft, nright));
        }

        public boolean queryRange(int left, int right) {
            Range target = ts.floor(new Range(left, MAX_VALUE));
            return target != null && target.left <= left && target.right >= right;
        }

        public void removeRange(int left, int right) {
            Range high = new Range(right, right);
            while (true) {
                Range r = ts.lower(high);
                if (r == null || r.right <= left) break;
                if (r.right > right) {
                    ts.add(new Range(right, r.right));
                }
                if (r.left < left) {
                    ts.add(new Range(r.left, left));
                }
                ts.remove(r);
            }
        }
    }
}
