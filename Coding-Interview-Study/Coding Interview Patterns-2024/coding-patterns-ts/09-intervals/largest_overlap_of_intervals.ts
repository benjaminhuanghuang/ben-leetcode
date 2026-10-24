/*
  Given a list of intervals, find the maximum number of overlapping intervals at any point.
  Maximum Balloons One Arrow Can Burst.

  "sweeping line algorithm." It works by processing the start and end points of intervals in order, 
  as if a vertical line was sweeping across them.
*/
import { Interval } from "./interval.js";

type PointType = "S" | "E";

interface Point {
  time: number;
  type: PointType;
}

function largest_overlap_of_intervals(intervals: Interval[]): number {
  // Convert the intervals into a list of points, marking each as a start or end point.
  const points: Point[] = [];

  for (const interval of intervals) {
    points.push({ time: interval.start, type: "S" });
    points.push({ time: interval.end, type: "E" });
  }

  // Sort in chronological order. If multiple points occur at the same
  // time, ensure end points are prioritized before start points.
  points.sort((a, b) => {
    if (a.time !== b.time) {
      return a.time - b.time;
    }
    return a.type.localeCompare(b.type);
  });

  // 'active' intervals is an interval has started but not ended.
  let activeIntervals = 0;
  let maxOverlaps = 0;

  // "sweeping line algorithm", sweep through the points, updating the count of active intervals
  for (const point of points) {
    if (point.type === "S") {
      activeIntervals += 1;
    } else {
      activeIntervals -= 1;
    }
    maxOverlaps = Math.max(maxOverlaps, activeIntervals);
  }

  return maxOverlaps;
}

/*


*/
