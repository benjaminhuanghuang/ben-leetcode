/*
42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/
*/

/*
Huahua
https://www.youtube.com/watch?v=StH5vntauyQ
*/

/*
Approach 1: Brute Force
for each slot, find the max left and right which takes O(N)
r[i] = min(max(high[0~i]),max(high[i~n-1]) - height[i]
ans  = sum(r[i])

Time complexity: O(N^2)   // search whole array for each slot to find max left and right
Space complexity: O(1)
*/
function trap_BruteForce_TLE(height: number[]): number {
  const n = height.length;
  let ans = 0;

  for (let i = 0; i < n; i++) {
    const l = Math.max(...height.slice(0, i + 1)); // duplicated operation
    const r = Math.max(...height.slice(i));
    ans += Math.min(l, r) - height[i];
  }

  return ans;
}
/*
Approach 2: DP
We can pre-compute the max of h[O~i] and h[i~n-1] in O(n)
l[1] means the max value from h[0] to h[i]
r[i] means the max value from h[i] to h[n-1]

l[1] = max(h[i], l[i-1]) i: 0 ~ n - 1
r[i] = max(h[i], r[i+1]) i: n -1 ~ 0  

Using l and r, For each column, query the max reduced 0(1)

Time complexity: 0(n)
Space complexity: 0(n)
*/
function trap_DP(height: number[]): number {
  const n = height.length;
  const l = new Array(n).fill(0);
  const r = new Array(n).fill(0);
  let ans = 0;

  for (let i = 0; i < n; ++i) {
    l[i] = i === 0 ? height[i] : Math.max(l[i - 1], height[i]);
  }

  for (let i = n - 1; i >= 0; --i) {
    r[i] = i === n - 1 ? height[i] : Math.max(r[i + 1], height[i]);
  }

  for (let i = 0; i < n; ++i) {
    ans += Math.min(l[i], r[i]) - height[i];
  }

  return ans;
}
