/*
Return an array of all overlaps between two arrays of intervals

Note: each individual interval array is sorted by start value,

因为两个列表都是按起点排序的，可以像「合并有序数组」一样，一次比较一对区间。
*/
import { Interval } from "./interval.js";

function identify_all_interval_overlaps(
  intervals1: Interval[],
  intervals2: Interval[]
): Interval[] {
  const overlaps: Interval[] = [];
  // two pointers to track current interval in each list
  let i = 0;
  let j = 0;

  while (i < intervals1.length && j < intervals2.length) {
    // Set A to the interval that starts first and B to the other interval.
    // A 始终是起点更早的那个区间
    let A: Interval, B: Interval;
    if (intervals1[i].start <= intervals2[j].start) {
      A = intervals1[i];
      B = intervals2[j];
    } else {
      A = intervals2[j];
      B = intervals1[i];
    }

    // If there's an overlap, add the overlap.
    if (A.end >= B.start) {
      overlaps.push({
        start: B.start,
        end: Math.min(A.end, B.end),
      });
    }

    // Advance the pointer associated with the interval that ends first.
    if (intervals1[i].end < intervals2[j].end) {
      i += 1;
    } else {
      j += 1;
    }
  }

  return overlaps;
}
/*
Time Complexity: O(N + M) where N and M are the lengths of the two input lists.
Space Complexity: O(1)
space complexity is only concerned with extra space used and not space taken up by the output.
*/
