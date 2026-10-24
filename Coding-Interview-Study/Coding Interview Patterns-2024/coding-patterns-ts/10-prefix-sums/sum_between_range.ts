class SumBetweenRange {
  private prefixSum: number[];

  constructor(nums: number[]) {
    this.prefixSum = [nums[0]];

    for (let i = 1; i < nums.length; i++) {
      this.prefixSum.push(this.prefixSum[this.prefixSum.length - 1] + nums[i]);
    }
  }

  sumRange(i: number, j: number): number {
    if (i === 0) {
      return this.prefixSum[j];
    }
    return this.prefixSum[j] - this.prefixSum[i - 1];
  }
}

/*
Time complexity: 
  - The time complexity of the constructor is O(n). where n denotes the length of the array.
    This is because we populate a prefix_sum array of length n. 
  - The time complexity of sum_range is O(1).
  
Space complexity: O(n) due to the space taken up by the prefix_sum array.
*/
