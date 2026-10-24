/*
436. Find Right Interval

https://leetcode.com/problems/find-right-interval/
*/

function findRightInterval(intervals: number[][]): number[] {
  const n = intervals.length;
  const original: Map<number, number> = new Map(); // start: index

  // Create a map from interval start to its index
  for (let i = 0; i < n; i++) {
    original.set(intervals[i][0], i);
  }

  // Result array
  const res: number[] = new Array(n).fill(-1);

  // Sort intervals by their start time
  intervals.sort((a, b) => a[0] - b[0]);

  // Binary search for the right interval
  for (let i = 0; i < n; i++) {
    let left = 0;
    let right = n - 1;
    while (left < right) {
      const mid = left + Math.floor((right - left) / 2);
      if (intervals[mid][0] >= intervals[i][1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    if (intervals[left][0] >= intervals[i][1]) {
      res[original.get(intervals[i][0])!] = original.get(intervals[left][0])!;
    }
  }

  return res;
}
