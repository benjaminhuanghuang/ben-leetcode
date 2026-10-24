/*
973. K Closest Points to Origin

https://leetcode.com/problems/k-closest-points-to-origin/
*/

import { PriorityQueue } from "./PriorityQueue";

function kClosest(points: number[][], k: number): number[][] {
  const pq = new PriorityQueue<number[]>(
    (a, b) => a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1],
    k
  );
  for (const point of points) {
    pq.add(point);
  }
  const ans: number[][] = [];
  while (k-- > 0) {
    ans.push(pq.poll()!);
  }
  return ans;
}
