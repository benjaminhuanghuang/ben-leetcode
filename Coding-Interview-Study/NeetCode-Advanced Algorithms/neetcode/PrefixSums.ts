/*
Q: Given an array of values, design a data structure that can query the sum of a subarray of the values.
 querySum(left, right)
*/

class PrefixSum {
  private prefix: number[];

  constructor(nums: number[]) {
    this.prefix = [];
    let total = 0;
    for (const n of nums) {
      total += n;
      this.prefix.push(total);
    }
  }

  rangeSum(left: number, right: number): number {
    const preRight = this.prefix[right];
    const preLeft = left > 0 ? this.prefix[left - 1] : 0; // if left is 0, we want to return the prefix sum at right
    return preRight - preLeft;
  }
}
