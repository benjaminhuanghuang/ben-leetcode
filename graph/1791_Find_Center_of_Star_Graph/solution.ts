/*
1791. Find Center of Star Graph

https://leetcode.com/problems/find-center-of-star-graph/
*/

function findCenter(edges: number[][]): number {
  // id -> indegree
  const degrees: Map<number, number> = new Map();

  for (const edge of edges) {
    degrees.set(edge[0], (degrees.get(edge[0]) || 0) + 1);
    degrees.set(edge[1], (degrees.get(edge[1]) || 0) + 1);
  }
  const n = degrees.size;
  for (const [i, degree] of degrees.entries()) {
    if (degree === n - 1) {
      return i;
    }
  }

  return -1;
}
