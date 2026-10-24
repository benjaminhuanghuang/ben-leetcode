/*
684. Redundant Connection

https://leetcode.com/problems/redundant-connection/
*/

/*
https://www.youtube.com/watch?v=4hJ721ce010 (HuaHua)
DFS
if there is an existed path between u and v, the edge [u, v] is redundant
*/
function findRedundantConnection(edges: number[][]): number[] {
  const graph: Map<number, number[]> = new Map();

  for (const edge of edges) {
    const [u, v] = edge;

    const visited: Set<number> = new Set();
    if (hasPath(u, v, graph, visited)) return edge;

    if (!graph.has(u)) graph.set(u, []);
    if (!graph.has(v)) graph.set(v, []);
    graph.get(u)?.push(v);
    graph.get(v)?.push(u);
  }
  return [];
}

// dfs
function hasPath(
  curr: number,
  goal: number,
  graph: Map<number, number[]>,
  visited: Set<number>
): boolean {
  if (curr === goal) return true;
  visited.add(curr);
  if (!graph.has(curr) || !graph.has(goal)) return false;
  for (const next of graph.get(curr)!) {
    if (visited.has(next)) continue;
    if (hasPath(next, goal, graph, visited)) return true;
  }
  return false;
}

export {};
