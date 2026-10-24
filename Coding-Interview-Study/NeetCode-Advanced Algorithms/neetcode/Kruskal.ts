/*
Kruskal's (Minimum Spanning Tree)


// Given a list of edges of a connected undirected graph,
// with nodes numbered from 1 to n,
// return a list of edges making up the minimum spanning tree.
*/

function minimumSpanningTree(
  edges: [number, number, number][],
  n: number
): [number, number][] {
  // Min heap sorted by weight
  const minHeap = new MinHeap();
  for (const [n1, n2, weight] of edges) {
    minHeap.push([weight, n1, n2]);
  }

  const unionFind = new UnionFind(n);
  const mst: [number, number][] = [];

  while (mst.length < n - 1) {
    const [weight, n1, n2] = minHeap.pop()!;
    if (!unionFind.union(n1, n2)) {
      continue; // Skip: would form a cycle
    }
    mst.push([n1, n2]);
  }

  return mst;
}

// Min Heap implementation
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

// UnionFind from earlier
class UnionFind {
  private par: Map<number, number> = new Map();
  private rank: Map<number, number> = new Map();

  constructor(n: number) {
    for (let i = 1; i <= n; i++) {
      this.par.set(i, i);
      this.rank.set(i, 0);
    }
  }

  find(n: number): number {
    let p = this.par.get(n)!;
    while (p !== this.par.get(p)!) {
      this.par.set(p, this.par.get(this.par.get(p)!)!);
      p = this.par.get(p)!;
    }
    return p;
  }

  union(n1: number, n2: number): boolean {
    const p1 = this.find(n1),
      p2 = this.find(n2);
    if (p1 === p2) return false;
    if (this.rank.get(p1)! > this.rank.get(p2)!) {
      this.par.set(p2, p1);
    } else if (this.rank.get(p1)! < this.rank.get(p2)!) {
      this.par.set(p1, p2);
    } else {
      this.par.set(p1, p2);
      this.rank.set(p2, this.rank.get(p2)! + 1);
    }
    return true;
  }
}

export {};
