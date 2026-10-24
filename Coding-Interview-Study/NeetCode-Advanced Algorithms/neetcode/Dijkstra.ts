/*
// Given a connected graph represented by a list of edges, where
// edge[0] = src, edge[1] = dst, and edge[2] = weight,
// find the shortest path from src to every other node in the graph.
// There are n nodes in the graph.

// O(E * logV), O(E * logE) 

弹出堆顶节点 [w1, n1] → 当前最短距离节点

如果 n1 已经确定最短距离，跳过（避免重复处理）

设置 n1 的最短距离为 w1

遍历 n1 的邻居 [n2, w2]

如果邻居还没确定最短距离

将新距离 w1 + w2 推入堆

循环直到堆空 → 所有节点最短距离确定
*/

function shortestPath(
  edges: [number, number, number][],
  n: number,
  src: number
): Map<number, number> {
  const adj: Map<number, [number, number][]> = new Map();
  for (let i = 1; i <= n; i++) {
    adj.set(i, []);
  }

  // s = src, d = dst, w = weight
  for (const [s, d, w] of edges) {
    adj.get(s)!.push([d, w]);
  }

  const shortest = new Map<number, number>();
  const minHeap = new MinHeap();
  minHeap.push([0, src]);

  while (minHeap.size > 0) {
    const [w1, n1] = minHeap.pop()!;
    if (shortest.has(n1)) {
      continue;
    }
    shortest.set(n1, w1);

    for (const [n2, w2] of adj.get(n1)!) {
      if (!shortest.has(n2)) {
        minHeap.push([w1 + w2, n2]);
      }
    }
  }

  return shortest;
}

class MinHeap {
  private heap: [number, number][] = [];

  push(val: [number, number]): void {
    this.heap.push(val);
    this.heap.sort((a, b) => a[0] - b[0]);
  }

  pop(): [number, number] | undefined {
    return this.heap.shift();
  }

  get size(): number {
    return this.heap.length;
  }
}
