/*
303. Range Sum Query - Immutable

https://leetcode.com/problems/range-sum-query-immutable/
*/

/*
https://www.youtube.com/watch?v=awS9dn_XCmI (Huahua)

Pre-process the data

sums[i] = nums[0] + nums[1] + … + nums[i]

sumRange(i, j) = sums[j] – sums[i – 1]

Time complexity: pre-compute: O(n), query: O(1)

Space complexity: O(n)

Brute Force: Query: O(n)
*/
class NumArray {
  private prefixSums: number[] = [];

  constructor(nums: number[]) {
    if (nums.length === 0) return;

    this.prefixSums.push(nums[0]);

    for (let i = 1; i < nums.length; ++i) {
      this.prefixSums.push(this.prefixSums[i - 1] + nums[i]);
    }
  }

  sumRange(left: number, right: number): number {
    if (left === 0) return this.prefixSums[right];
    return this.prefixSums[right] - this.prefixSums[left - 1];
  }
}
