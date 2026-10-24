/*
57. Insert Interval

https://leetcode.com/problems/insert-interval/
*/

function insert(intervals: number[][], newInterval: number[]): number[][] {
  // sort the intervals by start time
  intervals.sort((a, b) => a[0] - b[0]);

  const res: number[][] = [];
  let hasAdded = false; // flag to check if newInterval has been added

  // 4 cases:
  for (let i = 0; i < intervals.length; i++) {
    if (hasAdded) {
      res.push(intervals[i]);
    } else if (intervals[i][0] > newInterval[1]) {
      // newInterval is before the current interval, intervals[i].start > newInterval.end
      res.push(newInterval);
      res.push(intervals[i]);
      hasAdded = true;
    } else if (intervals[i][1] < newInterval[0]) {
      // newInterval is after the current interval, intervals[i].end < newInterval.start
      res.push(intervals[i]);
    } else {
      // merge the intervals[i] to newInterval
      newInterval[0] = Math.min(intervals[i][0], newInterval[0]);
      newInterval[1] = Math.max(intervals[i][1], newInterval[1]);
    }
  }

  if (!hasAdded) {
    res.push(newInterval);
  }

  return res;
}
