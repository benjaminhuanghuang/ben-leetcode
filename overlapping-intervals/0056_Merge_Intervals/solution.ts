/*
56. Merge Intervals

https://leetcode.com/problems/merge-intervals/
*/

function merge(intervals: number[][]): number[][] {
  if (intervals.length === 0) return [];

  // sort the intervals by start time
  intervals.sort((a, b) => a[0] - b[0]);

  const res: number[][] = [];

  for (let i = 0; i < intervals.length; i++) {
    let newInterval = [intervals[i][0], intervals[i][1]];

    // Merge the overlapping intervals: newInterval.end >= intervals[i + 1].start means overlapping
    while (i < intervals.length - 1 && newInterval[1] >= intervals[i + 1][0]) {
      // merge the intervals by extending the end of newInterval
      newInterval[1] = Math.max(newInterval[1], intervals[i + 1][1]);
      i++;
    }
    res.push(newInterval);
  }

  return res;
}
export {};
