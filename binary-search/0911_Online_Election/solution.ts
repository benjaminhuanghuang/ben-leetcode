/*
911. Online Election

https://leetcode.com/problems/online-election/
*/

class TopVotedCandidate {
  private times: number[];
  private wins: number[];

  constructor(persons: number[], times: number[]) {
    const n = persons.length;
    this.times = times;
    this.wins = new Array<number>(n).fill(0);
    const cnt: Array<number> = new Array<number>(n).fill(0);
    let cur = 0;
    for (let i = 0; i < n; ++i) {
      const p = persons[i];
      cnt[p]++;
      if (cnt[cur] <= cnt[p]) {
        cur = p;
      }
      this.wins[i] = cur;
    }
  }

  q(t: number): number {
    const search = (t: number): number => {
      let l = 0,
        r = this.times.length;
      while (l < r) {
        const mid = (l + r) >> 1;
        if (this.times[mid] > t) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      return l;
    };
    const i = search(t) - 1;
    return this.wins[i];
  }
}
