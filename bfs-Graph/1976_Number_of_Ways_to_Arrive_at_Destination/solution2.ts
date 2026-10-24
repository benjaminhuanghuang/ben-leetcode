/*
    Weighted Graph + Dijkstra
*/
import { PriorityQueue } from "../../heap/heap";

function countPaths(n: number, roads: number[][]): number {
  const MOD = 10 ** 9 + 7;

  // Create an adjacency list for the graph
  const graph: Map<number, Array<[number, number]>> = new Map();
  for (const [u, v, t] of roads) {
    if (!graph.has(u)) graph.set(u, []);
    if (!graph.has(v)) graph.set(v, []);
    graph.get(u)!.push([v, t]);
    graph.get(v)!.push([u, t]);
  }

  // Arrays to store the minimum time to reach each node and the number of ways to reach each node
  const times: number[] = new Array(n).fill(Infinity);
  const ways: number[] = new Array(n).fill(0);

  // Priority queue for Dijkstra's algorithm (sorted by time)
  const pq = new PriorityQueue<number[]>((a, b) => a[0] < b[0]); // [time, node]
  pq.add([0, 0]); // Start with [time 0, node 0]
  times[0] = 0;
  ways[0] = 1;

  while (pq.size() > 0) {
    const [currentTime, u] = pq.poll()!;

    if (u === n - 1) continue;

    for (const [v, t] of graph.get(u) || []) {
      const newTime = currentTime + t;
      if (newTime < times[v]) {
        // pruning
        times[v] = newTime;
        ways[v] = ways[u];
        pq.add([newTime, v]);
      } else if (newTime === times[v]) {
        ways[v] = (ways[v] + ways[u]) % MOD;
      }
    }
  }

  return ways[n - 1];
}

export {};
