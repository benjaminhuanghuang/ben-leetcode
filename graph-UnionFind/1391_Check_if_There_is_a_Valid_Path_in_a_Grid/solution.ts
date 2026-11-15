/*
Each street shape connects a fixed subset of {Left, Right, Up, Down}:
  1: L,R   2: U,D   3: L,D   4: R,D   5: L,U   6: R,U

Union two adjacent cells only if BOTH sides have a connector facing each
other (e.g. current cell has Right, and the cell to its right has Left).
Path exists iff (0,0) and (rows-1,cols-1) end up in the same component.

Time complexity: O(rows * cols) — amortized O(1) per union/find with path compression + rank.
Space complexity: O(rows * cols) — union-find parent/rank arrays.
*/
class UnionFind {
  parent: number[];
  rank: number[];

  constructor(size: number) {
    this.parent = Array.from({ length: size }, (_, i) => i);
    this.rank = new Array(size).fill(0);
  }

  find(x: number): number {
    if (this.parent[x] !== x) {
      this.parent[x] = this.find(this.parent[x]);
    }
    return this.parent[x];
  }

  union(x: number, y: number): void {
    const rootX = this.find(x);
    const rootY = this.find(y);
    if (rootX === rootY) return;

    if (this.rank[rootX] < this.rank[rootY]) {
      this.parent[rootX] = rootY;
    } else if (this.rank[rootX] > this.rank[rootY]) {
      this.parent[rootY] = rootX;
    } else {
      this.parent[rootY] = rootX;
      this.rank[rootX]++;
    }
  }
}

type Connectors = { L: boolean; R: boolean; U: boolean; D: boolean };

const STREET: Record<number, Connectors> = {
  1: { L: true, R: true, U: false, D: false },
  2: { L: false, R: false, U: true, D: true },
  3: { L: true, R: false, U: false, D: true },
  4: { L: false, R: true, U: false, D: true },
  5: { L: true, R: false, U: true, D: false },
  6: { L: false, R: true, U: true, D: false },
};

function hasValidPath(grid: number[][]): boolean {
  const rows = grid.length;
  const cols = grid[0].length;
  const index = (r: number, c: number) => r * cols + c;
  const uf = new UnionFind(rows * cols);

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      const cur = STREET[grid[r][c]];

      if (c + 1 < cols) {
        const right = STREET[grid[r][c + 1]];
        if (cur.R && right.L) uf.union(index(r, c), index(r, c + 1));
      }

      if (r + 1 < rows) {
        const down = STREET[grid[r + 1][c]];
        if (cur.D && down.U) uf.union(index(r, c), index(r + 1, c));
      }
    }
  }

  return uf.find(index(0, 0)) === uf.find(index(rows - 1, cols - 1));
}

export {};
