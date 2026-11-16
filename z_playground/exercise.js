/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
function merge(intervals) {
  // TODO: implement
  if (!intervals || intervals.length === 0) return [];

  intervals.sort((a, b) => a[0] - b[0]);

  const ans = [];
  let curr = intervals[0];

  for (let i = 1; i < intervals.length; i++) {
    if (intervals[i][0] > curr[1]) {
      ans.push(curr);
      curr = intervals[i];
    } else {
      curr[1] = Math.max(curr[1], intervals[i][1]);
    }
  }

  ans.push(curr);

  return ans;
}
