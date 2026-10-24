import { PriorityQueue } from "../../heap/heap";

/*
    https://algo.monster/liteproblems/787
*/
function findCheapestPrice(
  n: number,
  flights: number[][],
  src: number,
  dst: number,
  k: number
): number {
  // list contains the minimum costs of reaching each city from the source city with up to k stops
  let distances: number[] = new Array(n).fill(Number.MAX_SAFE_INTEGER); // Initialize all distances to "infinity" except the source.
  distances[src] = 0; // The distance from the source to itself is always 0.

  // Run the Bellman-Ford algorithm for K+1 iterations because you can have at most K stops in between,
  // which translates to K+1 edges in the shortest path.
  for (let i = 0; i <= k; ++i) {
    // Make a copy of the current state of distances before this iteration.
    const previousIterationDistances = distances.slice();

    // For each edge in the graph, try to relax the edge and update the distance to the destination node
    for (const flight of flights) {
      const [from, to, price] = flight;

      // Relaxation step: if the current known distance to 'from' plus the edge weight
      // to 'to' is less than the currently known distance to 'to', update it.
      if (previousIterationDistances[from] < Number.MAX_SAFE_INTEGER) {
        distances[to] = Math.min(
          distances[to],
          previousIterationDistances[from] + price
        );
      }
    }
  }

  // After K+1 iterations, if the distance to the destination is still "infinity", no such path exists;
  // otherwise, return the shortest distance to the destination.
  return distances[dst] === Number.MAX_SAFE_INTEGER ? -1 : distances[dst];
}

export {};
