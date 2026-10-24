/*
 Given a directed acyclical graph, return a valid
 topological ordering of the graph.
 图必须是 有向无环图（DAG）
 
*/
function topologicalSort(edges: [number, number][], n: number): number[] {
  const adj: Map<number, number[]> = new Map();
  for (let i = 1; i <= n; i++) {
    adj.set(i, []);
  }
  for (const [src, dst] of edges) {
    adj.get(src)!.push(dst);
  }

  const topSort: number[] = [];
  const visit = new Set<number>();

  for (let i = 1; i <= n; i++) {
    dfs(i, adj, visit, topSort);
  }

  topSort.reverse();
  return topSort;
}

function dfs(
  src: number,
  adj: Map<number, number[]>,
  visit: Set<number>,
  topSort: number[]
): void {
  if (visit.has(src)) {
    return;
  }
  visit.add(src);

  for (const neighbor of adj.get(src)!) {
    dfs(neighbor, adj, visit, topSort);
  }

  topSort.push(src);
}
