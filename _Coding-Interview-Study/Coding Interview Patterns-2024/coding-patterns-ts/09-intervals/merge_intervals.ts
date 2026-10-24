/*
  Given a list of intervals, merge all overlapping intervals and return an array of the
  non-overlapping intervals that cover all the intervals in the input.
*/
import { Interval } from "./interval.js";

export function mergeOverlappingIntervals(intervals: Interval[]): Interval[] {
  // step 1: sort intervals by their start time
  intervals.sort((a, b) => a.start - b.start);

  const result: Interval[] = [intervals[0]];

  for (let i = 1; i < intervals.length; i++) {
    const curr = intervals[i];
    const merged = result[result.length - 1];

    // If curr doesn't overlap, add curr to the merged list.
    if (merged.end < curr.start) {
      result.push(curr);
    }
    // If they do overlap, merge curr to the last merged interval.
    else {
      result[result.length - 1] = {
        start: merged.start,
        end: Math.max(merged.end, curr.end),
      };
    }
  }

  return result;
}

/*
Time complexity: The time complexity of merge_overlapping_intervals is O(n log(n)), where
n denotes the number of intervals. This is due to the sorting algorithm. The process of merging
overlapping intervals itself takes O(n) time because we iterate over every interval.

space complexity: The space complexity depends on the space used by the sorting algorithm. In
Python, the built-in sorting algorithm, Tim sort, uses O(n) space. Note that the merged array is
not considered in the space complexity calculation because we're only concerned with extra space
used, not space taken up by the output.
*/
