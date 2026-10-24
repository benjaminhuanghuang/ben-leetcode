/*
2529. Maximum Count of Positive Integer and Negative Integer

https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
*/
/*
由于数组是按非降序排序的，因此所有负数（如果有）都将位于数组的开头，后面是零，然后是正数。
可以通过查找大于或等于 的数字的第一个出现位置来确定正数的数量1。
正数的数量就是数组的总长度减去第一个正数的索引。
负数的数量是第一个非负数（可能是0）所在的索引，因为这个索引等于它之前的负数的数量
*/
function maximumCount(nums: number[]): number {
  const binarySearch = (target: number): number => {
    let left = 0;
    let right = nums.length;

    // While the search range is not empty
    while (left < right) {
      const mid = (left + right) >>> 1; // Equivalent to Math.floor((left + right) / 2)

      // Narrow down the search range based on the comparison with target
      if (nums[mid] < target) {
        left = mid + 1; // Target must be in the upper half of the range
      } else {
        right = mid; // Target is in the lower half or at the midpoint
      }
    }
    // Return the final index where the target should be inserted
    return left;
  };

  // 目标是找到第一个非负数（0或正整数）的索引, 这也是负整数的数量。
  const indexZero = binarySearch(0);
  // 目标是找到第一个正整数的索引
  const indexOne = binarySearch(1);

  // Calculate the maximum count of either zeroes or ones
  // by choosing the higher count between the two
  return Math.max(indexZero, nums.length - indexOne);
}
