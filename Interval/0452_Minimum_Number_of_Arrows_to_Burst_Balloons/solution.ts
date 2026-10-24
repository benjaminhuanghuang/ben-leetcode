/*
452. Minimum Number of Arrows to Burst Balloons

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/

/*
    sort the balloons based on their end times and then iterates through them, 
    counting the number of non-overlapping balloons. 
    The result is the minimum number of arrows required to burst all the balloons.
*/
function findMinArrowShots(points: number[][]): number {
  if (points.length === 0) return 0;

  // sort the points by end time
  points.sort((a, b) => a[1] - b[1]);

  let res = 1; // at least one arrow is needed
  let prevEnd = points[0][1]; // the end time of the first balloon

  for (let i = 1; i < points.length; i++) {
    if (points[i][0] > prevEnd) {
      // points[i].start > prevEnd means no overlapping, need a new arrow, reset the end
      res++;
      prevEnd = points[i][1];
    }
  }

  return res;
}
