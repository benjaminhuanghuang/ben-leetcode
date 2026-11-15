/*
Split nums into left, mid, right (all non-empty, contiguous) such that
sum(left) <= sum(mid) <= sum(right).

prefix[i] = sum of nums[0..i-1]. For a fixed left boundary i (left = nums[0..i-1]),
mid's end boundary j (mid = nums[i..j-1], right = nums[j..n-1]) must satisfy:
  prefix[j] - prefix[i] >= prefix[i]            => prefix[j] >= 2 * prefix[i]
  total - prefix[j] >= prefix[j] - prefix[i]    => 2 * prefix[j] <= total + prefix[i]

Since all nums[i] >= 1, prefix is strictly increasing, so as i grows the valid
j-range [lo, hi] only moves forward — two pointers instead of binary search.

Time complexity: O(n)
Space complexity: O(n)
*/
function waysToSplit(nums: number[]): number {
  const MOD = 1_000_000_007;
  const n = nums.length;

  const prefix = new Array(n + 1).fill(0);
  for (let i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + nums[i - 1];
  const total = prefix[n];

  let ans = 0;
  let lo = 1;
  let hi = 1;

  for (let i = 1; i <= n - 2; i++) {
    if (lo < i + 1) lo = i + 1;
    while (lo <= n - 1 && prefix[lo] < 2 * prefix[i]) lo++;

    if (hi < i + 1) hi = i + 1;
    while (hi + 1 <= n - 1 && 2 * prefix[hi + 1] <= total + prefix[i]) hi++;

    if (lo <= n - 1 && hi >= lo) {
      ans = (ans + (hi - lo + 1)) % MOD;
    }
  }

  return ans;
}

export {};
