/*
152. Maximum Product Subarray

https://leetcode.com/problems/maximum-product-subarray/
*/

function maxProduct(nums: number[]): number {
  if (nums.length === 0) return 0;

  let res = nums[0];
  const n = nums.length;
  const f = new Array(n).fill(0);
  const g = new Array(n).fill(0);

  f[0] = nums[0];
  g[0] = nums[0];

  for (let i = 1; i < n; ++i) {
    f[i] = Math.max(Math.max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
    g[i] = Math.min(Math.min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
    res = Math.max(res, f[i]);
  }

  return res;
}
