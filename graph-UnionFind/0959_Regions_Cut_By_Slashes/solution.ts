/*
959. Regions Cut By Slashes

https://leetcode.com/problems/regions-cut-by-slashes/
*/

/*
https://youtu.be/n3s9Q7GtfB4 (Huahua)
*/

class DSU {
  parent: number[];

  constructor(n: number) {
    this.parent = Array.from({ length: n }, (_, i) => i);
  }

  find(x: number): number {
    if (this.parent[x] !== x) {
      this.parent[x] = this.find(this.parent[x]);
    }
    return this.parent[x];
  }

  merge(x: number, y: number): void {
    this.parent[this.find(x)] = this.find(y);
  }
}

function regionsBySlashes(grid: string[]): number {
  const n = grid.length;
  const dsu = new DSU(4 * n * n);

  for (let r = 0; r < n; ++r) {
    for (let c = 0; c < n; ++c) {
      const index = 4 * (r * n + c);

      switch (grid[r][c]) {
        case "/":
          dsu.merge(index + 0, index + 3);
          dsu.merge(index + 1, index + 2);
          break;
        case "\\":
          dsu.merge(index + 0, index + 1);
          dsu.merge(index + 2, index + 3);
          break;
        case " ":
          dsu.merge(index + 0, index + 1);
          dsu.merge(index + 1, index + 2);
          dsu.merge(index + 2, index + 3);
          break;
        default:
          break;
      }

      if (r + 1 < n) {
        dsu.merge(index + 2, index + 4 * n + 0);
      }
      if (c + 1 < n) {
        dsu.merge(index + 1, index + 4 + 3);
      }
    }
  }

  let ans = 0;
  for (let i = 0; i < 4 * n * n; ++i) {
    if (dsu.find(i) === i) {
      ++ans;
    }
  }

  return ans;
}
