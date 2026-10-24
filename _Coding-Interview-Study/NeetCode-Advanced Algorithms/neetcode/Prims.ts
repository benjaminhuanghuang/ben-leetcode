/*

// Prim's Algorithm - Minimum Spanning Tree
*/

function minimumSpanningTree(
  edges: [number, number, number][],
  n: number
): [number, number][] {
  const adj: Map<number, [number, number][]> = new Map();
  for (let i = 1; i <= n; i++) {
    adj.set(i, []);
  }
  for (const [src, dst, weight] of edges) {
    adj.get(src)!.push([dst, weight]);
    adj.get(dst)!.push([src, weight]);
  }

  // Initialize the heap by choosing a single node
  // (in this case 1) and pushing all its neighbors
  const minHeap = new MinHeap();
  for (const [neighbor, weight] of adj.get(1)!) {
    minHeap.push([weight, 1, neighbor]);
  }

  const mst: [number, number][] = [];
  const visit = new Set<number>();
  visit.add(1);

  while (minHeap.size > 0) {
    const [weight, src, node] = minHeap.pop()!;
    if (visit.has(node)) {
      continue;
    }

    mst.push([src, node]);
    visit.add(node);

    for (const [neighbor, weight] of adj.get(node)!) {
      if (!visit.has(neighbor)) {
        minHeap.push([weight, node, neighbor]);
      }
    }
  }

  return mst;
}

class MinHeap {
  private heap: [number, number, number][] = [];

  push(val: [number, number, number]): void {
    this.heap.push(val);
    this.heap.sort((a, b) => a[0] - b[0]);
  }

  pop(): [number, number, number] | undefined {
    return this.heap.shift();
  }

  get size(): number {
    return this.heap.length;
  }
}

export {};
