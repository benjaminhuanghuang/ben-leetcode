/*
787. Cheapest Flights Within K Stops

https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/
import { PriorityQueue } from "../Heap/heap";

/*
    
*/
function findCheapestPrice(
  n: number,
  flights: number[][],
  src: number,
  dst: number,
  k: number
): number {
  // Build the graph
  const g: Map<number, Array<[number, number]>> = new Map();
  for (const e of flights) {
    if (!g.has(e[0])) {
      g.set(e[0], []);
    }
    g.get(e[0])!.push([e[1], e[2]]); // from -> [dist, price]
  }

  let ans = Number.MAX_SAFE_INTEGER;
  // Min heap, the element is [node, total cost, steps]
  const q = new PriorityQueue<[number, number, number]>(
    (a: number[], b: number[]) => a[1] < b[1]
  );
  q.add([src, 0, 0]); // Start with [src, cost 0, steps 0]

  while (q.size() > 0) {
    const [curr, cost, steps] = q.poll()!;

    if (curr === dst) {
      ans = Math.min(ans, cost);
    }

    if (steps > k) {
      continue;
    }

    if (g.has(curr)) {
      for (const [next, price] of g.get(curr)!) {
        if (cost + price >= ans) {
          continue; // Important: pruning
        }
        q.add([next, cost + price, steps + 1]);
      }
    }
  }

  return ans === Number.MAX_SAFE_INTEGER ? -1 : ans;
}
