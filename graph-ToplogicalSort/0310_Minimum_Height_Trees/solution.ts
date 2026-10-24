/*
310. Minimum Height Trees

https://leetcode.com/problems/minimum-height-trees/
*/

function findMinHeightTrees(n: number, edges: number[][]): number[] {
  if (n === 1) {
    return [0];
  }
  // node -> neighbors
  const graph: Set<number>[] = new Array(n).map(() => new Set<number>());

  for (const edge of edges) {
    graph[edge[0]].add(edge[1]);
    graph[edge[1]].add(edge[0]);
  }

  let leaves: number[] = [];

  for (let i = 0; i < n; ++i) {
    if (graph[i].size === 1) {
      // Leaf node has only one neighbor
      leaves.push(i);
    }
  }

  // Remove leaves level by level
  while (n > 2) {
    n -= leaves.length;
    const newLeaves: number[] = [];
    for (const leaf of leaves) {
      const neighbor = graph[leaf];
      for (const neighbor of graph[leaf]) {
        graph[neighbor].delete(leaf);
        if (graph[neighbor].size === 1) {
          newLeaves.push(neighbor);
        }
      }
    }
    leaves = newLeaves;
  }

  return leaves;
}
