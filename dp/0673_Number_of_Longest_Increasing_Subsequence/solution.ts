/*
673. Number of Longest Increasing Subsequence

https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

/*
  Solution: 
  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-673-number-of-longest-increasing-subsequence/
*/

function findNumberOfLIS(nums: number[]): number {
  const n = nums.length;
  if (n === 0) return 0;

  const c = new Array(n).fill(1);
  const l = new Array(n).fill(1);

  for (let i = 1; i < n; ++i) {
    for (let j = 0; j < i; ++j) {
      if (nums[i] > nums[j]) {
        if (l[j] + 1 > l[i]) {
          l[i] = l[j] + 1;
          c[i] = c[j];
        } else if (l[j] + 1 === l[i]) {
          c[i] += c[j];
        }
      }
    }
  }

  const max_len = Math.max(...l);
  let ans = 0;

  for (let i = 0; i < n; ++i) {
    if (l[i] === max_len) {
      ans += c[i];
    }
  }

  return ans;
}
