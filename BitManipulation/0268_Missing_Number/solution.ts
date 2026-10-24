/*
268. Missing Number

https://leetcode.com/problems/missing-number/
*/

function missingNumber(nums: number[]): number {
  const n = nums.length;
  let x = 0;
  for (let i = 1; i <= n; ++i) {
    // XOR the current index with the current array element and the current result.
    // This will cancel out all numbers from 0 to n except the missing one.
    x = x ^ i ^ nums[i - 1];
  }
  return x;
}

/*
    sum(0, n) = n * (n + 1) / 2
*/
function missingNumber2(nums: number[]): number {
  const n = nums.length;
  const sum = nums.reduce((acc, cur) => acc + cur, 0);
  return Math.floor(((0 + n) * (n + 1)) / 2) - sum;
}
