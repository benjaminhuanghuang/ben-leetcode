/*
435. Non-overlapping Intervals
    
https://leetcode.com/problems/non-overlapping-intervals/
*/
function eraseOverlapIntervals(intervals: number[][]): number {
  // 1. sort by start
  intervals.sort((i1, i2) => i1[0] - i2[0]);

  //
  let ans = 0;
  let prevEnd = intervals[0][1];

  for (let i = 1; i < intervals.length; i++) {
    const [start, end] = intervals[i];
    if (start >= prevEnd) {
      // no overlapping
      prevEnd = end;
    } else {
      ans += 1; // remove one
      prevEnd = Math.min(end, prevEnd);
    }
  }
  return ans;
}
