/*
1557. Minimum Number of Vertices to Reach All Nodes

https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
*/

function findSmallestSetOfVertices(n: number, edges: number[][]): number[] {
  // Initialize an array to count the in-degree of each vertex.
  const inDegreeCount: number[] = new Array(n).fill(0);

  for (const [_, to] of edges) {
    inDegreeCount[to]++;
  }

  const answer: number[] = [];

  for (let i = 0; i < n; ++i) {
    // If the in-degree of a vertex is 0, it means that it is not reachable from any other vertex.
    // Therefore, it must be included in the set.
    if (inDegreeCount[i] === 0) {
      answer.push(i);
    }
  }

  return answer;
}
