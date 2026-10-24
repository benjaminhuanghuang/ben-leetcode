/*
743. Network Delay Time

https://leetcode.com/problems/network-delay-time/
*/

/*
Approach: Dijsktra's algorithm

https://www.youtube.com/watch?v=vwLYDeghs_c   (Hua hua)
https://zxi.mytechroad.com/blog/graph/leetcode-743-network-delay-time/

Graph problem: single source all destinations shortest path.
Answer = Max(shortest path) 

Time complexity: O(N^2) -> O(NLogN*E)
Space complexity: O(N + E)
*/

import { PriorityQueue } from "../../heap/PriorityQueue";

function networkDelayTime(times: number[][], n: number, k: number): number {
  // adjacency list：u -> [(v, w), ...]
  const graph: Record<number, [number, number][]> = {};
  for (const [u, v, w] of times) {
    if (!graph[u]) graph[u] = [];
    graph[u]!.push([v, w]);
  }

  // distances 初始化
  const dist: number[] = Array(n + 1).fill(Infinity);
  dist[k] = 0;

  // 最小堆（[time, node]）
  const heap = new PriorityQueue<[number, number]>((a, b) => a[0] < b[0]);
  heap.add([0, k]);

  // Dijkstra
  const visited = new Set<number>();
  while (!heap.isEmpty()) {
    const [time, node] = heap.poll()!;

    if (visited.has(node)) continue;
    visited.add(node);

    if (graph[node]) {
      for (const [nei, w] of graph[node]!) {
        const newDist = time + w;
        if (newDist < dist[nei]) {
          dist[nei] = newDist;
          heap.add([newDist, nei]);
        }
      }
    }
  }

  // 检查是否所有节点都能到达
  let ans = 0;
  for (let i = 1; i <= n; i++) {
    if (dist[i] === Infinity) return -1;
    ans = Math.max(ans, dist[i]);
  }
  return ans;
}

export {};
