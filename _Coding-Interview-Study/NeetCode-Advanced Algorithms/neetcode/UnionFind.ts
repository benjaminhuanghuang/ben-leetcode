/*


*/
class UnionFind {
  private par: Map<number, number>;
  private rank: Map<number, number>;

  constructor(n: number) {
    this.par = new Map();
    this.rank = new Map();

    for (let i = 1; i <= n; i++) {
      this.par.set(i, i);
      this.rank.set(i, 0);
    }
  }

  find(n: number): number {
    let p = this.par.get(n)!;
    while (p !== this.par.get(p)!) {
      // Path compression
      this.par.set(p, this.par.get(this.par.get(p)!)!);
      p = this.par.get(p)!;
    }
    return p;
  }

  union(n1: number, n2: number): boolean {
    const p1 = this.find(n1);
    const p2 = this.find(n2);
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
