/*
1971. Find if Path Exists in Graph

https://leetcode.com/problems/find-if-path-exists-in-graph/
*/

function validPath(
  n: number,
  edges: number[][],
  source: number,
  destination: number
): boolean {
  // Build the graph
  const graph: Map<number, number[]> = new Map();
  for (const edge of edges) {
    const [u, v] = edge;
    if (!graph.has(u)) {
      graph.set(u, []);
    }
    if (!graph.has(v)) {
      graph.set(v, []);
    }
    graph.get(u)!.push(v);
    graph.get(v)!.push(u);
  }

  // BFS
  const visited: Set<number> = new Set();
  const queue: number[] = [source];
  visited.add(source);

  while (queue.length > 0) {
    const node = queue.shift();
    if (node === destination) {
      return true;
    }
    for (const neighbor of graph.get(node!) || []) {
      if (!visited.has(neighbor)) {
        visited.add(neighbor);
        queue.push(neighbor);
      }
    }
  }

  return false;
}
