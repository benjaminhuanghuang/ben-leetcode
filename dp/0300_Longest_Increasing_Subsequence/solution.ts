/*
300. Longest Increasing Subsequence

https://leetcode.com/problems/longest-increasing-subsequence/

O(n^2) solution -> O(nlogn) solution
*/
/*
    Brute force: O(2^n)
    DP: dp[i] means the length of the LIS ending with nums[i]
    Init: dp[i] = 1
    Transition: dp[i] = max(dp[i], dp[j] + 1) for 0 <= j < i and nums[j] < nums[i]

    answer = max(dp)
    Time complexity: O(n^2)
    Space complexity: O(n)
*/
function lengthOfLIS(nums: number[]): number {
  if (nums.length === 0) return 0;

  const n = nums.length;
  const dp: number[] = new Array(n).fill(1);

  for (let i = 1; i < n; ++i) {
    for (let j = 0; j < i; ++j) {
      if (nums[i] > nums[j]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }

  return Math.max(...dp);
}

/*
Solution 2: DP + Binary Search / Patience Sort

dp[i] := smallest tailing number of a increasing subsequence of length i + 1.

dp is an increasing array, we can use binary search to find the index to insert/update the array.

ans = len(dp)

Time complexity: O(nlogn)
Space complexity: O(n)
*/
function lengthOfLIS_2(nums: number[]): number {
  const n = nums.length;
  if (n === 0) return 0;

  const dp: number[] = [];

  for (let i = 0; i < n; ++i) {
    const num = nums[i];
    let left = 0,
      right = dp.length;

    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (dp[mid] < num) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left === dp.length) {
      dp.push(num);
    } else {
      dp[left] = num;
    }
  }

  return dp.length;
}
