/*
973. K Closest Points to Origin

Level: Medium

https://leetcode.com/problems/k-closest-points-to-origin
*/

/*
  Solution: 

  https://www.youtube.com/watch?v=zWiB3RGa-vo&ab_channel=HuaHua
*/

/**
 * @param {number[][]} points
 * @param {number} K
 * @return {number[][]}
 */
var kClosest = function (points, k) {
  points.sort((p1, p2) => {
    return p1[0] * p1[0] + p1[1] * p1[1] - p2[0] * p2[0] - p2[1] * p2[1];
  });

  return points.slice(0, k);
};
