/*
743. Network Delay Time

https://leetcode.com/problems/network-delay-time/
*/

/*
https://www.youtube.com/watch?v=vwLYDeghs_c   (Hua hua)
https://zxi.mytechroad.com/blog/graph/leetcode-743-network-delay-time/

Graph problem: single source all destinations shortest path.
Answer = Max(shortest path) 
Time complexity: O(N*E)
Space complexity: O(N)
*/
function networkDelayTime(times: number[][], n: number, k: number): number {
  const MAX_TIME = 101 * 100; // Max value is N * 100
  const dist: number[] = new Array(n).fill(MAX_TIME);
  dist[k - 1] = 0; // K to K the time is 0

  for (let i = 1; i < n; ++i) {
    for (const time of times) {
      const u = time[0] - 1;
      const v = time[1] - 1;
      const w = time[2];
      dist[v] = Math.min(dist[v], dist[u] + w);
    }
  }

  const maxDist = Math.max(...dist);
  return maxDist === MAX_TIME ? -1 : maxDist;
}
