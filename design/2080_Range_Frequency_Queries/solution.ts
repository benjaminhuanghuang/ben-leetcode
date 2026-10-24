/*
2080. Range Frequency Queries

https://leetcode.com/problems/range-frequency-queries/
*/
class RangeFreqQuery {
  private pos: Map<number, number[]>;

  constructor(arr: number[]) {
    this.pos = new Map();
    for (let i = 0; i < arr.length; i++) {
      if (!this.pos.has(arr[i])) this.pos.set(arr[i], []);
      this.pos.get(arr[i])!.push(i);
    }
  }

  query(left: number, right: number, value: number): number {
    const list = this.pos.get(value);
    if (!list) return 0;

    // Find first index >= left
    let l = this.lowerBound(list, left);
    // Find first index > right
    let r = this.upperBound(list, right);

    return r - l;
  }

  private lowerBound(arr: number[], target: number): number {
    let lo = 0,
      hi = arr.length;
    while (lo < hi) {
      const mid = Math.floor((lo + hi) / 2);
      if (arr[mid] < target) lo = mid + 1;
      else hi = mid;
    }
    return lo;
  }

  private upperBound(arr: number[], target: number): number {
    let lo = 0,
      hi = arr.length;
    while (lo < hi) {
      const mid = Math.floor((lo + hi) / 2);
      if (arr[mid] <= target) lo = mid + 1;
      else hi = mid;
    }
    return lo;
  }
}
