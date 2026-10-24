/*
1976. Number of Ways to Arrive at Destination

https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/

/*
    Weighted Graph + Dijkstra

*/
function countPaths(n: number, roads: number[][]): number {
  // build teh graph
  const graph: Map<number, Array<[number, number]>> = new Map();
  for (const [u, v, t] of roads) {
    if (!graph.has(u)) graph.set(u, []);
    if (!graph.has(v)) graph.set(v, []);
    graph.get(u)!.push([v, t]);
    graph.get(v)!.push([u, t]);
  }

  const times: number[] = new Array(n).fill(Number.MAX_SAFE_INTEGER);
  times[0] = 0;
  const ways: number[] = new Array(n).fill(0);
  ways[0] = 1;

  const pq: Array<[number, number]> = [[0, 0]]; // [shortest time, city]

  while (pq.length > 0) {
    pq.sort((a, b) => a[0] - b[0]); // Sorting by shortest time
    const [old_t, u] = pq.shift()!;
    if (!graph.has(u)) continue;
    for (const [v, t] of graph.get(u)!) {
      const new_t = old_t + t;
      if (new_t < times[v]) {
        pq.push([new_t, v]);
        times[v] = new_t;
        ways[v] = ways[u];
      } else if (new_t === times[v]) {
        ways[v] += ways[u];
      }
    }
  }

  const mod = 10 ** 9 + 7;
  return ways[n - 1] % mod;
}

export {};
