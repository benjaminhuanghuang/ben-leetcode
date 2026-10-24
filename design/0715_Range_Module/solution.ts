/*
715. Range Module

https://leetcode.com/problems/range-module/
*/

class RangeModule {
  private intervals: Array<[number, number]>;

  constructor() {
    this.intervals = [];
  }

  addRange(left: number, right: number): void {
    const res: Array<[number, number]> = [];
    let i = 0;

    // Add intervals completely before [left, right)
    while (i < this.intervals.length && this.intervals[i][1] < left) {
      res.push(this.intervals[i]);
      i++;
    }

    // Merge overlapping intervals
    while (i < this.intervals.length && this.intervals[i][0] <= right) {
      left = Math.min(left, this.intervals[i][0]);
      right = Math.max(right, this.intervals[i][1]);
      i++;
    }

    res.push([left, right]);

    // Add remaining intervals
    while (i < this.intervals.length) {
      res.push(this.intervals[i]);
      i++;
    }

    this.intervals = res;
  }

  queryRange(left: number, right: number): boolean {
    for (const [l, r] of this.intervals) {
      if (l <= left && right <= r) {
        return true;
      }
      if (r > left) break;
    }
    return false;
  }

  removeRange(left: number, right: number): void {
    const res: Array<[number, number]> = [];

    for (const [l, r] of this.intervals) {
      // No overlap
      if (r <= left || right <= l) {
        res.push([l, r]);
      } else {
        // Left remaining part
        if (l < left) {
          res.push([l, left]);
        }
        // Right remaining part
        if (right < r) {
          res.push([right, r]);
        }
      }
    }

    this.intervals = res;
  }
}
